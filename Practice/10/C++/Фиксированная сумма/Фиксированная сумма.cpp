#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double s, l1, l2, r1, r2, x1, x2;
    cin >> s >> l1 >> r1 >> l2 >> r2;
    x1 = l1;
    x2 = l2;
    OhShitHereWeGoAgain:
    if ((l1>=x1)&&(x1<=r1)) {
        if (x1 + x1 == s) {
            cout << x1 << x2;
            cout << 3;
        }
        else {
            x2 = x2 + 1;
            goto OhShitHereWeGoAgain;
            cout << 2;
            if (x2 >= r2) {
                x1 = x1 + 1;
                x1 = l1;
                if (x1 > r2) {
                    cout << "net takix";
                }
                goto OhShitHereWeGoAgain;
                cout << 1;
            }
        };
        
    }
    else { goto OhShitHereWeGoAgain; }
    cout << x1 << x2;
}