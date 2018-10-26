#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    string comet, group;
    cin >> comet >> group;

    int cometNumber {1}, groupNumber {1};

    for (auto character : comet) {
        cometNumber *= (character - 'A' + 1);
        cometNumber = cometNumber % 47;
    }

    for (auto character : group) {
        groupNumber *= (character - 'A' + 1);
        groupNumber = groupNumber % 47;
    }

    string result = (groupNumber == cometNumber)? "GO" : "STAY";
    cout << result << endl;

    return 0;
}