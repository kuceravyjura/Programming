#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int s, l1, l2, r1, r2, x1, x2;
    cin >> s >> l1 >> r1 >> l2 >> r2;
    x1 = l1; 
    x2 = r2;
    if (x1 + x2 >= s){
        x2 = max(s - x1, l2);
    }
    else{
        x1 = min(s - x2, r1);
    }
    if (x1 + x2 == s) { 
        cout << x1 << " " << x2 << endl;
   }
    else { 
        cout << -1 << endl;
  }
}