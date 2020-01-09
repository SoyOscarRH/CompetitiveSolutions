#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;


template <typename T>
T GCD(T a, T b) {
    T reminder;
    
    while(b != 0){ 
        reminder = a % b; 
        a = b;    
        b = reminder;     
    }

    return abs(a); 
}


using point = pair<int64_t , int64_t>;

int main () {
    
    int64_t points;

    int64_t XAxis {}, YAxis {};
    set<point> pointsIn13;
    set<point> pointsIn24;

    int64_t initialX, initialY;
    int64_t x, y;
    
    cin >> points >> initialX >> initialY;

    while (points--) {
        cin >> x >> y;

        x = x - initialX;
        y = y - initialY;

        if (x == 0) XAxis = 1;
        else if (y == 0) YAxis = 1;
        else if (x * y < 0) {
            x = abs(x);
            y = abs(y);

            int64_t gcd = GCD(x, y);
            pointsIn13.insert({x/gcd, y/gcd});
        }
        else if (x * y > 0) {
            x = abs(x);
            y = abs(y);

            int64_t gcd = GCD(x, y);
            pointsIn24.insert({x/gcd, y/gcd});
        }
    }

    cout << XAxis + YAxis + pointsIn13.size() + pointsIn24.size() << endl;

    
    return 0;
}