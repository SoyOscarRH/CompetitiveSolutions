#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using T = unsigned int;


int main () {

    T n = 1299709 + 20;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;                  
    vector<T> Primes(1, 2); 

    for (T i = 4; i <= n; i += 2) isPrime[i] = false;

    for (T i = 3; i <= n; i += 2) {                             
        if (isPrime[i]) {                                       
            Primes.push_back(i);                                
            
            if (i * i <= n)                                     
                for (T j = i * i; j <= n; j += 2 * i)           
                    isPrime[j] = false;                         
        }
    }



    int64_t test {};
    cin >> test;


    while (test != 0) {

        if (isPrime[test]) cout << 0 << endl;
        else {
            auto lowerIterator = lower_bound(Primes.begin(), Primes.end(), test);
            cout << *(lowerIterator) - *(--lowerIterator) << endl; 
        }

        cin >> test;
    }
    
    return 0;
}