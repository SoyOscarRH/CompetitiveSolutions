#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;



template <typename T>
void biggestPrimeFactor (T number) { 
    T exponent;    
    T n {number};             

    for (exponent = 0; (n & 1) == 0; ++exponent)    
        n = n >> 1;                                           
    if (exponent) cout << 2 << "^" << exponent << endl;

    for (T i = 3; i * i <= number; i += 2) {                           
        for (exponent = 0; (n % i) == 0; ++exponent) n /= i;      
        if (exponent) cout << i << "^" << exponent << endl;
    }
    
    if (n < 1) cout << 1 << "^" << n << endl;

}

int main () {

    biggestPrimeFactor<uint64_t>(600851475143);
    cout << (71 * 839 * 1471) << endl;
    return 0;
}