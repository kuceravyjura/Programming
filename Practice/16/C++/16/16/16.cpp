#include <iostream>
#include <string_view>
using namespace std;

int main() { 
    int check = 0;
    int count;string Tickets;string_view ticket;
    cin >> count;
   
    for (int i = 0; i < count; ++i) {
        cin >> Tickets;
        ticket = Tickets;
        if (ticket.starts_with('a') && ticket.ends_with("55661")) {
            check = 1;
            cout << ticket << " ";
        }
    }
    if (check == 0) {
        cout << "-1\n";
    }
}