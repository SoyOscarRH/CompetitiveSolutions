#include <iostream>                                                 
#include <string>                                                   
#include <vector>                                                   
using namespace std;                                                

typedef unsigned long long int lli;
typedef pair<lli,lli> PairOflli; 


vector<PairOflli> PrimeFactorization(lli Number) {                          
    vector<PairOflli> Factors;                                              
    lli Exponent = 0;                                                       

    for (; (Number & 1) == 0 ; ++Exponent)                                 
        Number >>= 1;                                                      

    if (Exponent) Factors.emplace_back(2, Exponent);                       

    for (lli i = 3; i*i <= Number; i += 2) {                                
        for (Exponent = 0; (Number % i) == 0; ++Exponent) Number /= i;      
        if (Exponent) Factors.emplace_back(i, Exponent);                    
    }

    if (Number > 1) Factors.emplace_back(Number, 1);                        
    return Factors;                                                         
}


int main(int argc, char const *argv[]) {
    
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; ++i) {
        lli Number;
        cin >> Number;

        auto Factors = PrimeFactorization(Number);

        lli divitions = 0;
        bool Used = false;

        for(auto Factor : Factors) {
            if (Factor.second > divitions) divitions = Factor.second;

        }

        cout << divitions << "\n";
    }
    return 0;
}

