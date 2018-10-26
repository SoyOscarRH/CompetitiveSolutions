#include <iostream>
#include <string>
#include <cmath>
using namespace std;

using lli = long long int;
using ull = unsigned long long int;

ull ModularBinaryExponentation(ull base, ull exponent, ull n) {     
    lli solution = 1;                                               
    base = base % n;                                                

    while (exponent > 0) {                                          
        if (exponent & 1) solution = (base * solution) % n;         
        
        base = (base * base) % n;                                   
        exponent = exponent >> 1;                                   
    }

    return solution;                                                
}

int main() {
    
    long long int B, P, M;
    while (cin >> B >> P >> M) {
        cout << ModularBinaryExponentation(B, P, M) << endl;
    }

    return 0;
}