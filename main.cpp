#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void airportTrafficRange(int low, int high, map<string, int>& traffic);

int main() {
    fstream fileInput{"data.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    map<string, int> airportTraffic;
    string initial{};
    string final{};
    while (fileInput >> initial >> final) {
        ++airportTraffic[initial];
        ++airportTraffic[final];
    }

    cout << "All airport traffic counts: \n";
    for (auto& each : airportTraffic) {
        cout << each.first << '\t' << each.second << '\n';
    }

    int highest{0};
    for (auto& airportCode : airportTraffic) {
        if (highest < airportCode.second) {
            highest = airportCode.second;
        }
    }

    cout << "\nBusiest airport(s) with count " << highest << ": \n";
    for (auto& airportCodeHighest : airportTraffic) {
        if (airportCodeHighest.second == highest) {
            cout << airportCodeHighest.first << ' '
                 << airportCodeHighest.second << '\n';
        }
    }

    airportTrafficRange(5, 8, airportTraffic);

    return 0;
}

void airportTrafficRange(int low, int high, map<string, int>& traffic) {
    cout << "Airports with traffic in range "
         << '[' << low  << ", " << high << "]\n";
    for (const auto& airport : traffic) {
        if (airport.second >= low && airport.second <= high) {
            cout << airport.first << '\n';
            cout << "TEST: " << airport.second << '\n';
        }
    }

}