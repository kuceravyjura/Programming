#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;
using json = nlohmann::json;

int main()
{
    std::map <int, int> s;
    std::ifstream par("in.json");
    json a = json::array();
    json sip;
    par >> sip;

    for (int i = 0; i < sip.size(); i++) {
        if (sip[i]["completed"] == true) {
            s[sip[i]["userId"]] += 1;
        }
    }

    for (auto e : s) {
        a.push_back({ {"userId", e.first},{"task_completed", e.second} });
    }

    std::cout << a.dump(3);
    std::ofstream out("out.json");
    out << std::setw(3) << a << '\n';
}