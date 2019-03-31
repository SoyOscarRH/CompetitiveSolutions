#include <iostream> 
#include <array> 
#include <algorithm> 
using namespace std; 
using num = int_fast32_t;
  

bool biggerImpact(num a, num b) { 
    return a > b; 
}

int main () {
    num n, litersIntoPipe, litersInTheFirstHole;
    cin >> n >> litersIntoPipe >> litersInTheFirstHole;

    array<num, 100002> holesSizes {};
    num sumOfNonBlockedHoles {0};
    
    for(num i = 0, holeSize; i < n; i++) {
        cin >> holeSize;
        holesSizes[i] = holeSize;
        sumOfNonBlockedHoles += holeSize;
    }
    
    num one {holesSizes[0]};
    sort(holesSizes.begin() + 1, holesSizes.begin() + n, biggerImpact);

    num blocked {0};
    for(int hole = 1; hole < n; hole++) {
        if (one * litersIntoPipe / sumOfNonBlockedHoles >= litersInTheFirstHole) break;

        sumOfNonBlockedHoles -= holesSizes[hole];
        blocked++;
    }

    cout<< blocked << endl;
}