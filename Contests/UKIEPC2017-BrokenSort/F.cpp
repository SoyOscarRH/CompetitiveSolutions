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
    if (AvailableFlips == 0) return AlreadyFlippedCoins;

    LongDouble& Result = Memory[AlreadyFlippedCoins][AvailableFlips];

    if (Result != -1) return Result;

    if (AlreadyFlippedCoins == NumberOfCoins)
        return Result = (
            NumberOfFlippedCoins(AlreadyFlippedCoins, AvailableFlips - 1) 
            +
            NumberOfFlippedCoins(AlreadyFlippedCoins - 1, AvailableFlips - 1)
            ) / 2.0; 
    
    return Result = (
        NumberOfFlippedCoins(AlreadyFlippedCoins, AvailableFlips - 1) 
        +
        NumberOfFlippedCoins(AlreadyFlippedCoins + 1, AvailableFlips - 1)
    ) / 2.0; 
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