#include <iostream> 
#include <ctime> 
#include <vector> 
#include <cmath> 
using namespace std;

template<class T>
vector<T> BozoSort(vector<T>a, int n, bool y) {
	int x1, x2, z = 0, check = 0;
	vector <int> b(n);
	while (1) {
		x1 = rand() % n;
		x2 = rand() % n;
		if (x1 != x2) {
			swap(a[x1], a[x2]);
			for (int i = 0; i < n - 1; i++) {
				if (a[i] <= a[i + 1]) {
					z++;
				}
				else {
					z = 0;
					break;
				}
				if (z == n - 1) {
					for (int i = 0; i < n; i++) {
						b[i] = a[i];
					}
					check = 1;
					break;
				}
			}
			if (check == 1) {
				if (y) {
					for (int i = 0; i < n; i++) {
						cout << b[i] << " ";
					}
				}
				else if (y == 0) {
					for (int i = n-1; i >= 0; i--) {
						cout << b[i] << " ";
					}
				}
				cout << "\n";
				return b;
				break;
			}
		}
	}
}
template<class T>
vector<T> BozoSort(vector <vector < T>>a, int n, bool y) {
	int y1, y2, y3, y4, chlen = 0, prov = 0, c = 0;
	vector <int> b(n);
	while (1)
	{
		int f = sqrt(n);
		y1 = rand() % f;
		y2 = rand() % f;
		y3 = rand() % f;
		y4 = rand() % f;
		if (y1 != y3 || y2 != y4) {
			swap(a[y1][y2], a[y3][y4]);
				for (int i = 0; i <= sqrt(n) - 1; i++) {
					for (int j = 0; j <= sqrt(n) - 1; j++) {
						if (j == sqrt(n) - 1) {
							if (i == sqrt(n) - 1) {
								if (chlen == n - 1) {
									for (int i = 0; i < sqrt(n); i++) {
										for (int j = 0; j < sqrt(n); j++) {
											b[c] = a[i][j];
											c++;
										}
									}
									prov = 1;
									break;
								}
								else {
									break;
								}
							}
							if (a[i][j] <= a[i + 1][0]) {
								chlen++;
							}
							else {
								chlen = 0;
								break;
							}
						}
						else {
							if (a[i][j] <= a[i][j + 1]) {
								chlen++;
							}
							else {
								chlen = 0;
								break;
							}
						}
					}
				}

			if (prov == 1) {
				if (y) {
					for (int i = 0; i < n; i++) {
						cout << b[i] << " ";
					}
				}
				else if (y == 0) {
					for (int i = n - 1; i >= 0; i--) {
						cout << b[i] << " ";
					}
				}
				cout << "\n";
				return b;
				break;
			}
		}
	}
}

template<class T>
vector<T> BozoSort(vector<T>a, bool y){
	if (y == 1){
		return BozoSort(a, 3, y);
	}
	else
		return BozoSort(a, 3, y);
}


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, k = 0;
	cout << "Введите количество элементов в массиве n: ";cin >> n;
	vector <int> a(n);
	vector <vector < int>> b(sqrt(n), vector<int>(sqrt(n)));

	cout << "Введите n элементов массива\n";
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < sqrt(n); i++){
		for (int j = 0; j < sqrt(n); j++){
			b[i][j] = a[k];
			k++;
		}
	}
	cout << "\n";
	BozoSort(a, n, 1);
	BozoSort(a, n, 0);
	BozoSort(b, n, 1);
	BozoSort(b, n, 0);
	BozoSort(a, 1);
	BozoSort(a, 0);
}