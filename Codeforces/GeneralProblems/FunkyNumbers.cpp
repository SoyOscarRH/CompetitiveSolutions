#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
using ull = unsigned long long int;
using lli = long long int;

bool isTriangularNumber(ull result, const vector<ull>& triangularNumbers) {

    unordered_set<ull> isATriangle(triangularNumbers.begin(), triangularNumbers.end());

    for (const auto& number : triangularNumbers) 
        if (isATriangle.find(result - number) != isATriangle.end()) 
            return true;

    return false;
}

template <typename item>
lli BinarySearch(const vector<item> &A, lli left, lli right, item toFind) {
    lli actualPosition;

    while (left <= right) {
        actualPosition = left + (right -left) / 2;

        if (A[actualPosition] == toFind) return actualPosition;
        if (A[actualPosition] < toFind) left = actualPosition + 1;
        else right = actualPosition - 1;
    }

    return -1;
}

bool isTriangularNumberBS(ull result, const vector<ull>& triangularNum) {

    for (const auto& number : triangularNum) {
        ull toFind = result - number;
        if (BinarySearch<ull>(triangularNum, 0, triangularNum.size(), toFind) != -1)
            return true;
    }

    return false;
}



vector<ull> preCalculateTriangularNumbers(ull limit) {
    vector<ull> triangularNumbers;
    ull i = 1, triangularNumber = 0; 
    
    while (triangularNumber < limit) {
        triangularNumber = (i * (i+1) ) / 2;
        triangularNumbers.push_back(triangularNumber);
        i++;
    }

    return triangularNumbers;
}

int main () {

    ull number;
    cin >> number;

    auto triangularNumbers = preCalculateTriangularNumbers(number);
    if (isTriangularNumberBS(number, triangularNumbers)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
