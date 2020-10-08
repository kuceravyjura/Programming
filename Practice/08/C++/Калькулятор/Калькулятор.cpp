#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char x;
	double a, b, c;
	cin >> a >> x >> b;
	switch (x) {
	case '+':
		c = a + b;
		cout << c;
		break;
	case '-':
		c = a - b;
		cout << c;
		break;
	case '*':
		c = a * b;
		cout << c;
		break;
	case '/':
		c = a / b;
		cout << c;
		break;
	default:
		return false;
		break;
	}
}