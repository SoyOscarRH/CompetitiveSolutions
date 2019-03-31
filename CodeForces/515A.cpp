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
    int64_t a, b, steps;
    cin >> a >> b >> steps;
    if (isPossible(abs(a), abs(b), steps)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0; 
} 