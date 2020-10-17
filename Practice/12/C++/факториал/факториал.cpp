#include <iostream>
using namespace std;
int main()
{
	double i, s, count,n;
	cin >> n;
	count = 1;
	s = 1;
	for(i=1;i<=n;i++){
		s = s* count;
		count = count + 1;
	}
	cout <<"s = "<< s;
}