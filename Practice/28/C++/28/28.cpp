#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print_factorization(unsigned int x){
    map <unsigned int, unsigned int> a;
    while (x > 1){
        for (unsigned int i = 2; i <= x; i++){
            if (!(x % i)){
                x /= i;
                a[i] = a.count(i) ? a[i] + 1 : 1;
                break;
            }
        }
    }
    int check = 1;
    for (auto b : a){
        if (b.second > 1){
            cout << "*" << b.first << "^" << b.second;
        }
        else { (cout << check == 1) ? "*" : '' << b.first; /*if (check == 1) { check--; }*/ }
    }
}
int main(){
    unsigned int n;
    cin >> n;
    print_factorization(n);
}
