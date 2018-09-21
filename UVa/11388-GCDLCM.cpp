#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int main () {


    int testCases {};
    cin >> testCases;

    while (testCases--) {
        int64_t gcd, lcm;
        cin >> gcd >> lcm;

        if (lcm % gcd != 0) cout << "-1\n";
        else cout << gcd << " " << lcm << endl;
    }
    
    return 0;
}