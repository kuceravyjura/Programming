#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double x, n, i;
    cin >> n;
    x = 0;
    i = 0;
    while (x <= n) {
        x = pow(2, i);
        if (x <= n)
            i++;
    }
    cout << i << endl;
}