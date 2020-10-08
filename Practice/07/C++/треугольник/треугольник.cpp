#include <iostream>
using namespace std;
int main()
{
    int x;
    double a, b, c, p, S,x1,x2,x3,y1,y2,y3;
    setlocale(LC_ALL, "Russian");
    cout << "1 - через длины сторон\n2 - через координаты\n";
    cin >> x;
    switch (x) {
    case 1:
        cout << "Введите длины сторон \n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        if ((a > 0) && (b > 0) && (c > 0))
        {
            if ((a + b > c) && (a + c > b) && (b + c > a))
            {
                p = (a + b + c) / 2;
                S = sqrt(p * (p - a) * (p - b) * (p - c));
                cout << "S = " << S << endl;
            }
            else cout << "не треугольник так как одна из сторон больше суммы двух других сторон" << endl;
        }
        else { cout << "Длина стороны не может быть отрицательной"; }
        break;
    case 2:
        cout << "Введите координаты первой точки\n";
        cin >> x1 >> y1;
        cout << "Введите координаты второй точки\n";
        cin >> x2 >> y2;
        cout << "Введите координаты третьей точки\n";
        cin >> x3 >> y3;
        a = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        b = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            p = (a + b + c) / 2;
            S = sqrt(p * (p - a) * (p - b) * (p - c));
            cout << "S = " << S << endl;
        }
        else cout << "не треугольник так как одна из сторон больше суммы двух других сторон" << endl;
        break;
    default:
        return false ;
    };
}
