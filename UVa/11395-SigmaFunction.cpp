#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;


int main () {
    int64_t number {};
    cin >> number;

    while (number) {

        int64_t numberOfPerfectSquares = sqrt(number);
        int64_t numberOfDoublesPerfectSquares = sqrt(number / 2);
        cout << number - numberOfPerfectSquares - numberOfDoublesPerfectSquares << endl;

        cin >> number;
    }
    
    return 0;
}