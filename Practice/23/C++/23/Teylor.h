#ifndef Teylor
#define Teylor
#include "fact.h"
double sinusdecay(double x, int k) {
    if (k < 1)
        return -2;

        double sum = 0;
        int u = 1;

    for (int i = 0; i < k; ++i) {
        int n = i * 2 + 1;
        double z = u;
        for (int o = 0; o < n; ++o) {
            z *= x;
        }
            z /= fact(n);
            sum = sum + z;
            u = u* (-1);
    }
        return sum;
}
#else
#error Teylor alredy incuded 
#endif
