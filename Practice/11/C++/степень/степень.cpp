#include <iostream>
int main()
{
    int i;
    int b;
    double a;
    double v;
    std::cin >> a;
    std::cin >> b;
    v = a;
    for (i = 1; i <= (b - 1); i++) {
        a = a * v;
    };
    std::cout << a;
}