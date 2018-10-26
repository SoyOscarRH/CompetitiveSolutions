#include <iostream>
#include <vector>
#include <set>
using namespace std;

using lli = long long int;
using ull = unsigned long long int;

template<typename T>
std::set<T> EratosthenesSievePrimes(T n) {                   
    std::vector<bool> isPrime(n + 1, true);                     
    std::set<T> Primes{2};                                

    for (T i = 3; i <= n; i += 2) {                             
        if (isPrime[i]) {                                       
            Primes.insert(i);                                
            
            if (i * i <= n)                                     
                for (T j = i * i; j <= n; j += 2 * i)           
                    isPrime[j] = false;                         
        }
    }

    return Primes;                                              
}


int main() {
    
    auto data = EratosthenesSievePrimes<ull>(1000005);

    ull n, a;
    while (cin >> n) {
        if (n == 0) break;
        for (auto start = data.begin(); start != data.end(); start++) {
            a = *start;
            if (data.count(n - a) != 0) {
                printf("%lld = %lld + %lld\n", n, a, n - a);
                break;
            }
        }
    }

    return 0;
}


