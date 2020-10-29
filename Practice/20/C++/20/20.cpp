#include <iostream>

int main()
{
	long long cash, count;
	std::string name, z;
	int price, volume, x, y, g, priceforlitter, buchloamount, check;
	std::cin >> cash >> count;
	x = 0; y = 0; volume = 0; check = 0;

	for (int i = 0; i < count; ++i) {
		std::cin >> name >> price >> volume;
		priceforlitter = price / volume;
		buchloamount = cash / priceforlitter;
		if (buchloamount >= 1 and buchloamount > x) {
			x = buchloamount;
			z = name;
			y = cash - (buchloamount * priceforlitter);
			g = x / volume;
			check = 1;
		}
	}
	if (check == 1) {
		std::cout << z << " " << g << "\n";
		std::cout << x << "\n";
		std::cout << y;
	}
	else std::cout << "-1";
}