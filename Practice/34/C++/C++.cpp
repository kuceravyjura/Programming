#include <iostream>
#include <string>
#include <cmath>
#include <locale>


using namespace std;


void create(int** massive, int const size, const int start, const int step)
{
	int* arr = new int[size];
	*arr = start;
	for (int i = 1; i < size; i++)
	{
		*(arr + i) = *(arr + i - 1) + step;
	}
	*massive = arr;
}


void sort(int* massive, int len)
{
	int x, j;
	for (int i = 1; i < len; ++i)
	{
		x = massive[i];
		j = i - 1;
		while (j >= 0 && massive[j] > x)
		{
			massive[j + 1] = massive[j];
			--j;
		}
		massive[j + 1] = x;
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

void destroy(int** massive)
{
	delete[] * massive;
	*massive = nullptr;
}


int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "russian");

	int size, step = 0, begin = 0;

	cout << "Введите размер начало и шаг арифметической прогрессии" << endl;
	cin >> size >> begin >> step;
	int* massive;
	create(&massive, size, begin, step);
	sort(massive, size);
	print(massive, size);
	destroy(&massive);
}