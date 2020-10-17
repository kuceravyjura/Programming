#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int s, i,n,x;
    cin >> s;
    n = 0;
    for (i = 1; i <= s; i++) {
        x = s / i; 
        if (x % i == 0) {
            n = n + 1;
        }
    }
    if (n >= 3) {
        cout << "составное";
    }
    else
        cout << "простое";
}
