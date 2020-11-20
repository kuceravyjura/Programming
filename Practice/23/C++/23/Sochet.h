#ifndef Sochet
#define Sochet
#include "fact.h"
double sochet(int k, int n) {
	double x = fact(n)/(fact(k)*fact(n-k));
	return x;
}
#else
#error sochet alredy incuded 
#endif
