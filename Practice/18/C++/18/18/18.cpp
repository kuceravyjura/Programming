#include <iostream>
#include <string>
#include<map>
#include<cmath>
using namespace std;

int main()
{
    long long x = 1;
    string stop;
    string txt = "halloklempnerdasistfantastischfluggegecheimen";
    map<char, int> dict;
    for (int i = 0; i < txt.size(); i++){
        dict[txt[i]]++;
    }
    cin >> stop;
    for (int i = 0; i < stop.size(); i++){
        x = x * dict[stop[i]];
    }
    cout << x / pow(txt.size(), stop.size());
    return 0;
}


