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

    return 0;
}