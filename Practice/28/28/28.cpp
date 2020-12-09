#include <iostream>
using namespace std;
void print_factorization(int n) {
    int i = abs(n);
    int count = 0;int count2 = 0; int count3 = 0;
    
    for (;i > 0 ; ) {
        i--;
        if (n % i == 0) {
            count++;
            for (int j = i;j > 0;) {
                j--;
                if (j == 0|| count2 != 0)
                    break;
                if (i % j == 0) {
                    int z = 1;
                    if (i/j == n/i ) {
                        z++;
                        for (int o = j; o > 0;) {
                            o--;
                            if (o == 0) break;
                            if (count3 == 1) break;
                            
                            if (j % o == 0 && o != 1) {
                                count3++;
                                count2++;
                                if (j / o == i / j)z++;
                                if (i / j == o)z++;
                                
                                cout << i / j << "^" << z;
                                
                                if (j / o != i / j) cout << " * " << i / o;
                                if (o != i / j) {
                                    for (int p = 2; p < 15;) {
                                        for (int k = 10; k > 1;) {
                                            k--;

                                            double y = o;
                                            double e = pow(pow(p, 10), 1 / k);

                                            if (y / e == 1) {
                                                if (p == i / j) z = z + k;
                                                cout << " * " << p << "^" << k;
                                            }

                                        }
                                        p++;
                                    }
                                }
                                else cout << " * " << o;
                                
                            }
                        }
                        if (count2 != 0) break;
                        cout << i / j <<"^"<< z<< " * " << j  << endl;
                        count2++;
                        
                    }
                    else {
                        cout << i / j << " * " << j << " * " << n / i << endl;
                        count2++;
                    }
                }
            }
            if (count2 == 0) {
                cout << i  <<  " * " << n / i << endl;
            }
        }
        if (count == 1)
            break;
    }
}

int main()
{
    int x;
    cin >> x; cout << '\n';
    print_factorization(x);

}

