#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
T countDivisors(T n) { 
    T exponent, count = 1; 
    
    for (exponent = 0; (n & 1) == 0; ++exponent)  
        n = n >> 1;     
    if (exponent) count *= (exponent + 1);

    for (T i = 3; i * i <= n; i += 2) {     
        for (exponent = 0; (n % i) == 0; ++exponent) n /= i;  
        if (exponent) count *= (exponent + 1);
    }
    
    if (n > 1) count *= (1 + 1);

    return count;
}

int main() {

    uint64_t a , b;
	cin >> a >> b;

    auto x = __gcd(a, b);
    cout << getDivisors(x) << endl;


}

