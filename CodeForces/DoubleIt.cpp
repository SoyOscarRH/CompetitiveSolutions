//@see https://codeforces.com/group/PzLcHnJr9l/contest/243872/problem/D

#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

template <typename T>
void backwardStep(T num, string& stepsEncoded) {
    if (num == 1) stepsEncoded += "A";
    else if (num == 2 or num == 0) stepsEncoded += "B";
    else {
        if (num % 2 == 0) {
            stepsEncoded += "B";
            backwardStep<T>((num-2) / 2, stepsEncoded);
        }
        else {
            stepsEncoded += "A";
            backwardStep<T>((num-1) / 2, stepsEncoded);
        }
    }
}

template <typename T>
string findTheSteps(T finalNumber) {
    string stepsEncoded {};
    backwardStep<T>(finalNumber, stepsEncoded);
    reverse(stepsEncoded.begin(), stepsEncoded.end());
    return stepsEncoded;
}
 

int main() {
    int64_t finalNumber;
    cin >> finalNumber;

    cout << findTheSteps<int64_t>(finalNumber) << endl;
    return 0;
}