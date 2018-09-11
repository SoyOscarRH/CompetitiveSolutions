#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
using namespace std;

int countingValleys(int n, string& path) {

    int currentLevel {}, numberOfValleys {};

    for (auto& move : path) {
        if (move == 'U') currentLevel++;
        else currentLevel--;

        if (currentLevel == 0 and move == 'U') numberOfValleys++;
    }

    return numberOfValleys;
}