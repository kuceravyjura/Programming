#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void loadImage();
    void saveImage();
    void encodeText();
    void decodeText();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void showMessage(QString msg);

    Ui::MainWindow *ui;
    QImage image;
    bool imageLoaded;
    size_t imageCapacity;
    size_t usedBytes;

    const std::array<char, 3> marker {
        static_cast<char>(0b11100010),
        static_cast<char>(0b10011101),
        static_cast<char>(0b10100100)
    };
    // количество байт, отводимых под размер спрятанного сообщения
    const size_t messageInfoLength = 4;
};
#endif // MAINWINDOW_H
