#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "russian");
    double a, c, b, x, x1,y;
    cout << "введите переменную a" << endl;
    cin >> a;
    cout << "введите переменную b" << endl;
    cin >> b;
    cout << "введите переменную c" << endl;
    cin >> c;
    y = sqrt(b * b - (4 * a * c));
    if (a != 0) {
        if (b != 0) {
            if (c != 0) { 
                if (y>0) {
                    x = ((b * (-1)) + sqrt(b * b - (4 * a * c))) / (2 * a);
                    cout << "Первый корень " << x << endl;
                    x1 = ((b * (-1)) - sqrt(b * b - (4 * a * c))) / (2 * a);
                    cout << "второй корень " << x1 << endl;
                }
                else if (y == 0) { x = (-b)/ (2 * a);
                cout << "корень равен = " << x << endl;
                } else{
                    cout << "корнец нет";
                    return(0);
                }
            }
            else
            {
                x1 = -b / a;
                cout << "корень " << x1 << endl;
            }
        }
        else {
            if (c != 0) {
                x = sqrt(-c / a);
                cout << "Первый корень " << x << endl;
                x1 = -sqrt(-c / a);
                cout << "второй корень " << x1 << endl;
            }
            else {
                cout << "x = 0" << endl;
            }
        }
    }
    else {
        if (b != 0) {
            if (c != 0) {
                x = -c / b;
                cout << "корень равен " << x << endl;
            }
          }
        else {
            cout << "Корней нет"<< endl;
        }
    }
}