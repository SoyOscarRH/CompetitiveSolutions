#include <iostream> 
#include <vector> 
using namespace std; 

template<typename T>
auto get_non_divisors(T until) -> vector<T> {
    auto non_divisors = vector<T> (until + 1);
    for (T i = 0; i <= until; ++i)
        non_divisors[i] = i - 2;

    for (T i = 3; i * i <= until; i++) {
        for (T i = 0; i < ; i++) {
            
        }
        
        if (until % i == 0) { 
            if (until / i != i) non_divisors[i] -= 2;
            else non_divisors[i + 1] -= 1;
        } 
    }
    
    return non_divisors;
}

int main() { 
    auto tests = 0;
    cin >> tests;

    auto non_divisors = get_non_divisors<int>(10);

    for (auto test = 1; test <= tests; ++test) {
        auto N = 0;
        cin >> N;

        cout << "case #" << test << ": " << non_divisors[N] << '\n';
    }

    return 0; 
} 