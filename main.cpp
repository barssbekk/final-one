#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

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

    cout << "#########################\n";

    int highest{0};
    for (auto airportCode : airportTraffic) {
        if (highest < airportCode.second)
            highest = airportCode.second;
    }
    cout << "Highest: " << highest;


    return 0;
}