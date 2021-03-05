#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primes;
vector<bool> isPrime;
void primesSieve(ll n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(ll i = 4; i <= n; i += 2) isPrime[i] = false;
	ll limit = sqrt(n);
	for(ll i = 3; i <= n; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(ll j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}


vector<pair<ll, int>> factorize(ll n){
	vector<pair<ll, int>> f;
	for(ll p : primes){
		if(p * p > n) break;
		int pot = 0;
		while(n % p == 0){
			pot++;
			n /= p;
		}
		if(pot) f.emplace_back(p, pot);
	}
	if(n > 1) f.emplace_back(n, 1);
	return f;
}



int main (){
    
    primesSieve(1e5);
    int t; cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        
        if(a == 1){
            
            if(b == 1){
                cout << "0\n";
            } else {
                auto x = factorize(b);
                cout << x.size() << "\n"; 
            }
            
        } else {
            if(b == 1){
                auto x = factorize(a);
                cout << x.size() << "\n"; 
            } else {
                set<ll> factors;
                for(ll p : primes){
                    if(p * p > a) break;
                    int pot = 0;
                    while(a % p == 0){
                        pot++;
                        a /= p;
                    }
                    if(pot) factors.insert(p);
                }
                if(a > 1) factors.insert(a);
                
                for(ll p : primes){
                    if(p * p > b) break;
                    int pot = 0;
                    while(b % p == 0){
                        pot++;
                        b /= p;
                    }
                    if(pot) factors.insert(p);
                }
                if(b > 1) factors.insert(b);
                
                cout << factors.size() << "\n";
                
            }
        }
        
    }
    
    return 0;
}
