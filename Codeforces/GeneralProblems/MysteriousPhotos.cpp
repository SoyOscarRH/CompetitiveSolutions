#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


double sdistance(long int x1, long int y1, long int x2, long int y2) {
    auto one = (x1- x2);
    auto two = (y1- y2);
    return sqrt( one * one + two * two);
}


using point = pair<int64_t , int64_t>;

int main () {
    

    vector<long double> distances1(3);
    vector<long double> distances2(3);
    long int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    distances1[0] = sdistance(x1, y1, x2, y2);
    distances1[1] = sdistance(x2, y2, x3, y3);
    distances1[2] = sdistance(x3, y3, x1, y1);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    distances2[0] = sdistance(x1, y1, x2, y2);
    distances2[1] = sdistance(x2, y2, x3, y3);
    distances2[2] = sdistance(x3, y3, x1, y1);

    sort(distances1.begin(), distances1.end());
    sort(distances2.begin(), distances2.end());

    double ratio = distances2[0] / distances1[0];

    if ( 
        (abs( (distances1[1] * ratio) - distances2[1]) < 0.00001) 
        and 
        (abs( (distances1[2] * ratio) - distances2[2]) < 0.00001) 
    )
    cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}