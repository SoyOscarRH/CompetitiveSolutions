
#include <iostream> 
using namespace std; 
  
bool isPossible(uint64_t x, uint64_t y, uint64_t steps) { 
    // simple path is always smaller
    if (steps < x + y) return false;

    // use simple path an then move stupid
    if ((steps - (x + y)) % 2 == 0) return true; 
  
    return false; 
} 
  
int main() { 
    int64_t numberOfMoves {}, x1 {}, y1 {}, x2 {}, y2 {};
    cin >> numberOfMoves >> x1 >> y1 >> x2 >> y2;
    uint64_t finalX = abs(x2 - x1);
    uint64_t finalY = abs(y2 - y1);

  
    uint64_t total {};
    for (uint64_t i = 1; i <= numberOfMoves; i++) {
        if (isPossible(finalX, finalY, i)) total++;
    }
    cout << total << endl;

    return 0; 
} 