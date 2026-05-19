#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream fileInput{};
    if (!fileInput)
        cerr << "File not found\n";

    map<string, int> airportTraffic;
    string initial{};
    string final{};
    while (fileInput >> initial >> final) {
        airportTraffic[initial] =
    }

    return 0;
}