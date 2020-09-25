// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double t;
    double v0;
    double x0;
    double x;
    double a = 9.8;
    cin >> t >> v0  >> x0;
    x = x0 + v0 * t - a * t * t / 2;
    cout << "расстояние" << x;







}

