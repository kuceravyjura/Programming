#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>
#include <QBitArray>
#include <QFile>
#include <QTextStream>

bool getBit(const QImage &img, int index) {
    int pixelIndex = index / 3;

    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

#ifndef NDEBUG
    if (y >= img.height())
        throw std::out_of_range("индекс бита выходит за пределы картинки");
#endif

    //img.pixel returns #AARRGGBB
    switch (index % 3) {
    case 0:
        return (img.pixel(x, y) >> 16) & 1;
    case 1:
        return (img.pixel(x, y) >> 8) & 1;
    default:
        return img.pixel(x, y) & 1;
    }

    Q_UNREACHABLE();
}

void setBit(QImage &img, int index, bool val) {
    int pixelIndex = index / 3;

    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

#ifndef NDEBUG
    if (y >= img.height())
        throw std::out_of_range("выходит за пределы картинки");
#endif

    //img.pixel returns #AARRGGBB
    switch (index % 3) {
    case 0:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x010000) | (val << 16));
    case 1:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000100) | (val << 8));
    default:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000001) | val);
    }
}

void writeBytes(QImage& img, size_t begin, QByteArray& byteArray) {
    size_t end = (begin + byteArray.size()) * 8;

#ifndef NDEBUG
    if (static_cast<size_t>(img.width() * img.height() * 8 * 3) <= end)
        throw std::out_of_range("попытка записать биты вне картинки");
#endif

    for (size_t i = begin * 8; i < end; ++i) {
        setBit(img, i, (byteArray[i / 8] >> (7 - i % 8)) & 1);
    }
}

void MainWindow::loadImage()
{
    imageLoaded = false;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Допустимые форматы (*.png)"));
    if(!fileName.size()){
        return;
    }
    if (!image.load(fileName)){
        ui->label->setText("Изображение не загружено");
        return;
    }
    image.convertTo(QImage::Format_ARGB32);
    ui -> label->setText("Изображение успешно загружено");
    // каждый пиксель может хранить информацию в 3х каналах RGB
    // часть размера картинки уйдёт на запись маркера и размера сообщения
    imageCapacity = (image.width() * image.height() * 3) / 8 - marker.size() - messageInfoLength;
    imageLoaded = true;

}

void MainWindow::saveImage()
{
    if (!imageLoaded) {
            ui->label->setText(tr("Изображение не загружено в программу!"));
            return;
        }

        QString filepath = QFileDialog::getSaveFileName(this, tr("Сохранить картинку"), "", tr("Допустимые форматы (*.png)"));

        if (image.save(filepath, "PNG")) {
            ui->label->setText(tr("Изображение успешно сохранено в %1").arg(filepath));
        } else {
            ui->label->setText(tr("Изображение не сохранено"));
        }
}

void MainWindow::encodeText()
{
    QByteArray byteArray;
        byteArray.push_back(marker);
        for (int i = messageInfoLength - 1; i >= 0; --i) {
            byteArray.push_back((usedBytes >> i*8) & 0xff);
        }
        byteArray.push_back(ui->plainTextEdit->toPlainText().toUtf8());

        writeBytes(image, 0, byteArray);

        ui->label->setText(tr("Сообщение добавлено в картинку!"));
}

QByteArray readBytes(const QImage& img, size_t begin, size_t length) {
    QByteArray byteArray;
    char buf = 0;

    size_t end = (begin + length) * 8;

#ifndef NDEBUG
    if (static_cast<size_t>(img.width() * img.height() * 8 * 3) <= end)
        throw std::out_of_range("попытка прочитать биты вне картинки");
#endif

    for (size_t i = begin * 8; i < end; ++i) {
        buf = (buf << 1) | getBit(img, i);

        if (i % 8 == 7) {
            byteArray.push_back(buf);
            buf = 0;
        }
    }

    return byteArray;
}

void MainWindow::decodeText()
{
    if (!imageLoaded) {
        ui->label->setText(tr("Изображение не загружена в программу!"));
        return;
    }

    int headerSize = marker.size() + messageInfoLength;
    QByteArray byteArray;

    byteArray = readBytes(image, 0, headerSize);

    for (size_t i = 0; i < marker.size(); ++i) {
        if (marker[i] != byteArray[i]) {
            ui->label->setText(tr("Сообщение не обнаружено"));
            return;
        }
    }

    size_t messageSize = 0;
    for (size_t i = marker.size(); i < marker.size() + messageInfoLength; ++i) {
        messageSize = (messageSize << 8) + static_cast<unsigned char>(byteArray[i]);
    }

    if (messageSize > imageCapacity) {
        // showMessage(tr("Сообщение не обнаружено"));
        ui->label->setText(tr("Ошибка. Размер сообщения в заголовке превышает размер изображения"));
        return;
    }

    byteArray = readBytes(image, headerSize, messageSize);

    QString text = QString::fromUtf8(byteArray);

    ui->plainTextEdit->setPlainText(text);

    ui->label->setText(tr("Присутствует сообщение длиной %1 байт").arg(messageSize));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->saveImgButton, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->encodeMsgButton, &QPushButton::clicked, this, &MainWindow::encodeText);
    connect(ui->decodeMsgButton, &QPushButton::clicked, this, &MainWindow::decodeText);

    imageCapacity = -1; // по-умолчанию размер картинки невалидный
    usedBytes = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
