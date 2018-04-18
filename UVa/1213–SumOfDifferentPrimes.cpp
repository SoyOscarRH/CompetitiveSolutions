// =========================================================================
// =========================     UVa: 1213     =============================
// =========================================================================
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;                                                            //Sorry kids
 
typedef unsigned long long ull;                                                 //Just a so long name, sorry
typedef long long lli;                                                          //Just a so long name, sorry



// ====================================================================
// ================       ALREADY SOLVED CODE          ================
// ====================================================================

    // ********* ERATOSTHENES SIEVE / GET PRIMES USING BOOLS *************
    vector<bool> EratosthenesSieveBoolVector(ull Size){                         //FN: To check if i is prime: Vector[i]
        vector<bool> BoolPrimes(Size+1, true);                                  //Ok, first, allocate space

        BoolPrimes[0] = false;                                                  //Now, 0 is not prime :o
        BoolPrimes[1] = false;                                                  //Now, 1 (maybe) is not prime :o

        for (lli i = 4; i <= Size; i+= 2) BoolPrimes[i] = false;                //Eliminate all the pairs

        for (lli i = 3; i*i <= Size; i+= 2) {                                   //Check for every # < √i (Math things) 
            if (BoolPrimes[i])                                                  //If we still believe it's a prime
                for (ull j = i*i; j <= Size; j+= 2*i)                           //Remove all his multiples-Special limit
                    BoolPrimes[j] = false;                                      //For each multiple just remove it
        }

        return BoolPrimes;                                                      //Return the info to know if n is prime
    }

    // ********* GET PRIMES / PRIMES UNTIL AN N FACTOR ******************
    vector<ull> PrimeVectorUsingSieve(const vector<bool> &BoolPrimes){          //FN: Return vector with all primes < n
        vector<ull> VectorOfPrimes;                                             //Were we will have all the Primes

        for (ull i = 0, Size = BoolPrimes.size(); i <= Size; ++i)               //For each element of the Bool vector
            if (BoolPrimes[i] == true) VectorOfPrimes.push_back(i);             //If it´s prime then add it to the Vector

        return VectorOfPrimes;                                                  //Return vector 
    }


// ====================================================================
// ================       SOLUTION CODE                ================
// ====================================================================
#define N 2048
#define K 16
#define P 309
 
long long NumberOfWays[N][K][P];

vector<ull> Primes = PrimeVectorUsingSieve(EratosthenesSieveBoolVector(N));     //Create Vector with all primes until Size


// ======================================================
// ================       DP SOLUTION       =============
// ======================================================
ull DPFindNWaysToSumPrimes(int n, int k, int i) {                               //This is the DP
    if (n == 0 and k == 0)                                                      //Stupid case 
        return 1;                                                               //Stupid case {}
    if (n < 0 or k < 0 or Primes[i] > n or i == P)                              //Now, If i'm off limits then:    
        return 0;                                                               //no solutions papu

    if (NumberOfWays[n][k][i] != -1) return NumberOfWays[n][k][i];              //If I have been there use solution

    ull SolutionsPartA = DPFindNWaysToSumPrimes(n - Primes[i], k - 1, i + 1);   //2 Possibles roads
    ull SolutionsPartB = DPFindNWaysToSumPrimes(n, k, i + 1);                   //2 Possibles roads
    
    NumberOfWays[n][k][i] = SolutionsPartA + SolutionsPartB;                    //Go new solution
    
    return NumberOfWays[n][k][i];                                               //Now we have a solution
}
 

int main() {
    memset(NumberOfWays, -1, sizeof NumberOfWays);                              //Set all to -1

    int n, k;                                                                   //Now just call the cases
    while (cin >> n >> k and (n or k))                                          //Now just call the cases
        cout << DPFindNWaysToSumPrimes(n, k, 0) << "\n";                        //Now just call the cases

    return 0;
}