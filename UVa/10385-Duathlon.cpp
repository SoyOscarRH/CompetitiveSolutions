#include <iostream>
#include <array>
#include <functional>

using namespace std;
int totalDistance;

const double eps = 1e-9;

array<double, 20> running_speed, biking_speed;
int players;

double margin(double runningLength) {
    double me = runningLength / running_speed[players - 1] + (totalDistance - runningLength) / biking_speed[players - 1];
    double them = 1e100;
    for (int i = 0; i < players - 1; ++i) {
        them = min(them,  runningLength / running_speed[i] + (totalDistance - runningLength) / biking_speed[i]);
    }
    return them - me;
}


template <typename domain>
domain ContinuousTernarySearch(
    const function<domain(domain)> &f, unsigned int iterations, domain left, domain right) { 
    domain leftThird, rightThird;

    while (iterations--) {
        leftThird = left + (right - left) / 3;
        rightThird = right - (right - left) / 3;

        if ( f(leftThird) < f(rightThird) ) left = leftThird;
        else right = rightThird;
    }

    return (left + right) / 2;
}


int main() {
    while (cin >> totalDistance) {
        cin >> players;
        for (int i = 0; i < players; ++i) {
            cin >> running_speed[i] >> biking_speed[i];
        }
        
        double r = ContinuousTernarySearch<double>(margin, 150, 0, totalDistance);
        double m = margin(r);
        if (m < 0.0) {
            printf("The cheater cannot win.\n");
        } else {
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",  m * 3600, r, totalDistance - r);
        }
    }
    return 0;
}