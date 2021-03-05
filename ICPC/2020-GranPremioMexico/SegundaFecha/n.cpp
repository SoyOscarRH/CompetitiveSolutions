#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


vector<ll> primes;
vector<bool> isPrime;

void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}

bool itsPrime(ll p){
    for(ll i: primes){
        if(i*i > p)break;
        if(p % i == 0)return false;
    }
    return true;
}

vector<ll> factorize(ll n){
	vector<ll> f;
	for(ll p : primes){
		if(p * p > n) break;
		int pot = 0;
		while(n % p == 0){
			pot++;
			n /= p;
		}
		if(pot) f.emplace_back(p);
	}
	if(n > 1) f.emplace_back(n);
	return f;
}


int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    primesSieve(31622800);

    int n, m, k;
    cin>>m>>n>>k;

    vector<ll> Nnodos(n);
    for(int i = 0; i < n; i++)cin>>Nnodos[i];

    for(int i = 0; i < k; i++){
        int m, n, d;
        cin>>m>>n>>d;
    }

    set<ll>primos;
    for(int i = 0; i < Nnodos.size(); i++){

        if( itsPrime(Nnodos[i]) ){

            primos.insert(Nnodos[i]);


        }else{
            auto fact = factorize(Nnodos[i]);
            for(auto x: fact){
                primos.insert(x);
            }
        }

    }

    for(ll primo: primos){
        cout<<primo<<" ";
    }
    cout << "\n" ;



    return 0;
}
