/*================================================================
=================     FLIPPED COINS         ======================
==================================================================

http://codeforces.com/gym/101606
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long double LongDouble;

LongDouble Memory[405][405];

int NumberOfCoins, NumberOfFlips;

LongDouble NumberOfFlippedCoins(int AlreadyFlippedCoins, int AvailableFlips) {
    if (AvailableFlips == 0) return AlreadyFlippedCoins;                                    //If you dont have any possible moves

    LongDouble& Result = Memory[AlreadyFlippedCoins][AvailableFlips];                       //Get the calculated result

    if (Result != -1) return Result;                                                        //If already calculated, add the result


    if (AlreadyFlippedCoins == NumberOfCoins) {                                             //As you have flipped all the coins
        auto Option1 = NumberOfFlippedCoins(AlreadyFlippedCoins, AvailableFlips - 1);       //All is the same
        auto Option2 = NumberOfFlippedCoins(AlreadyFlippedCoins - 1, AvailableFlips - 1);   //You flip back a coin

        return Result = (Option1 + Option2) / 2.0;                                          //Now just probability
    }

    auto Option1 = NumberOfFlippedCoins(AlreadyFlippedCoins, AvailableFlips - 1);           //All is the same
    auto Option2 = NumberOfFlippedCoins(AlreadyFlippedCoins + 1, AvailableFlips - 1);       //You flip back a coin

    return Result = (Option1 + Option2) / 2.0;                                              //Now just probability
}

int main() {

    cout << fixed << setprecision(8);

    for (int i = 0; i < 405; ++i)
        for (int j = 0; j < 405; ++j)
            Memory[i][j] = -1;

    cin >> NumberOfCoins >> NumberOfFlips;

    cout << NumberOfFlippedCoins(0, NumberOfFlips) << "\n";

    return 0;
}