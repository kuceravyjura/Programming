#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "russian");

    double a;
    double c;
    double b;
    double x;
    double x1;
    cout << "введите переменную a"<<endl;
    cin >> a;
    cout << "введите переменную b" << endl; 
    cin >> b;
    cout << "введите переменную c" << endl; 
    cin >> c;
    
     x = ((b * (-1)) + sqrt(b * b - (4 * a * c))) / (2 * a);
     cout << x <<endl;
     x1 = ((b * (-1)) - sqrt(b * b - (4 * a * c))) / (2 * a);
     cout << x1 <<endl;
}
