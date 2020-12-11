#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;
vector<int> sort(vector<int> x) {
	for (int i = 1; i < size(x); ++i)
	{
		for (int r = 0; r < size(x) - i; r++)
		{
			if (x[r] < x[r + 1])
			{
				swap(x[r], x[r + 1]);
			}
		}
	}
	return(x);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	
	std::cout << "Введите количество сигналов\n";
	std::cin >> n;
	std::cout << "Введите сигналы\n";
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}int c = 1;
	vector<int> b;
	for (int i = 0;i < n;i++) {
		b.push_back(a[i]);
		b = sort(b);
		for (int c = 0; c < size(b); c++) {
			cout << b[c]<< ' ';
		}
		cout << endl;
	}
}