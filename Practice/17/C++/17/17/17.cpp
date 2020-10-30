#include<iostream>
using namespace std;

int main(){
	const int n = 37;
	int x,reds,blaks,p;
	reds = 0;blaks = 0;p = 0;x = 0;
	int a[n];
	for (int i = 0; i < n; i++){
		a[i] = 0;
	}
	int red[18] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	while (x>=0){
		cin >> x;
		if (x < 0){
			break;
		}
		else{
			a[x]++;
			for (int i = 0; i <= 17; i++){
				if (x == red[i]){
					reds++;
					break;
				}
				else if (i == 17){
					blaks++;
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (a[i] > p) p = a[i];
		}
		for (int i = 0; i < n; i++){
			if (a[i] == p) cout << i << " ";
		}
		cout << '\n';
		for (int i = 0; i < n; i++){
			if (a[i] == 0) cout << i << " ";
		}
		cout << '\n' << reds<<' ' << blaks << '\n'<<'\n';
	}
}