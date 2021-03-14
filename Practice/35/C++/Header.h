#pragma once
#include <iostream>
using namespace std;

void print(int* massive)
{
    cout << "массив :";
    cout << "\n[";
    for (int i = 0; i < massive.size; i++) {
        cout << " ";
        cout << massive[i];
        if (i == massive.size - 1) { cout << "] \n"; break; }
        cout << ", ";
    }
    cout << "] \n";
}