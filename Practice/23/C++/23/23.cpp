#include <iostream>
#include <iomanip>
#include "fact.h"
#include "Teylor.h"
#include "Sochet.h"

int main(){
    setlocale(LC_ALL, "russian");
    int a = 1;
    int n, k;
    double x;
    double PI = 3.1415926535;
    while (a == 1) {
        std::cout << "Выберите что хотите сделать" << '\n' << "1 расчитать факториал" << '\n' 
            << "2 расчитать синус" << '\n' << "3 количество сочетаний" << '\n' << "4 вывести таблицы" << '\n';
        int y;
        std::cin >> y; std::cout << '\n';
        if (y == 1) {
            std::cin >> n;
            std::cout << fact(n);
        }
        if (y == 2) {
            std::cin >> k >> x;
            std::cout << sinusdecay(x, k);
        }
        if (y == 3) {
            std::cin >> k >> n;
            std::cout << sochet(k, n);
        }
        if (y == 4) {
            std::cout << "n\tn!" << std::endl;
            for (int i = 1; i <= 10; ++i) {
                std::cout << i << "\t" << fact(i) << std::endl;
            }   std::cout << std::endl;
            std::cout << "x\tsin(x)" << std::endl;
            std::cout << std::setprecision(4);
            for (double x = 0; x <= PI / 4; x += PI / 180) {
                std::cout << x << "\t" << sinusdecay(x, 5) << std::endl;
            }   std::cout << std::endl;
            std::cout << "k\tC(k, 10)" << std::endl;
            for (int k = 1; k <= 10; ++k) {
                std::cout << k << "\t" << sochet(k, 10) << std::endl;
            }
        }


        std::cout << "Нажмите 1 если хотите повторить программу "; std::cin >> a;
    }
}
