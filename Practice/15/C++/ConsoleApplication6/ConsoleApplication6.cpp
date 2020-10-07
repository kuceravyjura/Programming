#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "russian");
    int i,a,y,n;
    srand((unsigned)time(0));
    n = (rand() % 100) + 1;
    for (i = 0; i <= 4;i++) {
        cout << "введите число "<<endl;
        cin >> a;
        if (a == n) {
            cout << "Поздравляю! Вы угадали" <<endl << "Хотите начать с начала? (1 - Да)"<<endl;
            cin >> y;
            if (y == 1)return main(); else return 0;
}
        else {
            if (a < n) cout << "Загаданное число больше"<<endl;
            
            
            else cout << "Загаданно число меньше"<<endl;
        }
    }
    cout << "Вы проиграли. Было загаданно: " << n<<endl<<"Хотите начать с начала? (1 - Да)"<<endl;
    cin >> y;
    if (y == 1)return main(); else return 0;
}