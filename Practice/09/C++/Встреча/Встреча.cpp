#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char s;
	int h1, m1, h2, m2,a;
	cin >> h1 >> s >> m1;
	cin >> h2 >> s >> m2;
	if ((h2 - h1) == 0) {
		a = m2 - m1;
		if ((-15 <= a) || (a <= 15)) { cout << "встреча состоится"; }
		else { cout << "встреча не состоится"; };
	}
	else {
		if ((h2 - h1) > 0) {
			m2 = m2 + 60;
			a = m2 - m1;
			if(a <= 15) { cout << "встреча состоится"; }
			else { cout << "встреча не состоится"; };
		}
		else if((h2 - h1) < 0) {
			m1 = m1 + 60;
			a = m1 - m2;
			if (a <= 15) { cout << "встреча состоится"; }
			else { cout << "встреча не состоится"; };
		};
	};
}