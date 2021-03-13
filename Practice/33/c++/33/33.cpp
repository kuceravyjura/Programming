#include <iostream>
using namespace std;
int *create(int len, int begin = 0, int step = 0)
{
    int* ptr = new int[len];
    ptr[0] = begin;
    for (int i = 1; i < len; i++) 
    {
        ptr[i] = ptr[i - 1] + step;
    }
    return ptr;
}

void sort(int* massive, int len)
{
    int x, j;
    for (int i = 1; i < len; ++i)
    {
        x = massive[i];
        j = i-1;
        while (j >= 0 && massive[j] > x)
        {
            massive[j+1] = massive[j];
            --j;
        }
        massive[j+1]= x;
    }
}

void print(int* massive, int len)
{
    cout << "массив :";
    cout << "\n[";
    for (int i = 0; i < len; i++) {
        cout << " ";
        cout << massive[i];
        cout << " ";
    }
    cout << "] \n";
}

int main() 
{
    setlocale(LC_ALL, "russian");
    int len, begin = 0, step = 0;
    cout << "Введите длину массива"<<endl;
    cin >> len;
    cout << "Введите начальный член"<<endl;
    cin >> begin;
    cout << "Введите шаг прогрессии"<<endl;
    cin >> step;
    int* massive = create(len, begin, step);
    create(len, begin, step);
    sort(massive, len);
    print(massive, len);
    delete[] massive;
}