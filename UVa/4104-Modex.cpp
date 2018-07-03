#include <iostream>                                                 
using namespace std;                                                

typedef unsigned long long int lli;


lli ModularExponentation(lli Base, lli Exponent, lli n) {                  
    lli Solution = 1, Auxiliar = Base;                                     

    while (Exponent != 0) {                                                

        if (Exponent & 1) {                                                 
            Solution = (Auxiliar * Solution) % n;                           
            Auxiliar = (Auxiliar * Auxiliar) % n;                           
            Exponent = Exponent >> 1;                                       
        } 
        else {                                                         
            Auxiliar = (Auxiliar * Auxiliar) % n;                      
            Exponent = Exponent >> 1;                                  
        }
    }

    return Solution;                                                     
}


int main(int argc, char const *argv[])
{
    
    lli testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; ++i)
    {
        lli x, y, n;
        cin >> x >> y >> n;

        cout << ModularExponentation(x, y, n) << "\n";
    }

    return 0;
}