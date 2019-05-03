#include <iostream>
#include <set>
#include <cstdint>

using namespace std;

int32_t gcd(int32_t a, int32_t b) {
    if (a == 0 and b == 0) return 1;
    int32_t r {};
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

using point = tuple<int32_t, int32_t, int32_t>;

int main() {
    int32_t num;
    cin >> num;


    set<point> data {};

    int32_t a, b, c, min;
    int32_t aE, bE, cE;

    cin >> aE >> bE >> cE;
    for (int i = 0; i < num - 1; i++) {
        cin >> a >> b >> c;
        a -= aE;
        b -= bE;
        c -= cE;

        min = gcd(gcd(a, b), c);
        if (min == 0) min = 1;


        point p {a/min, b/min, c/min};
        point inverseP {-1 * a/min, -1 * b/min, -1 * c/min};
        bool isNotHere = data.find(inverseP) == data.end();
        if (isNotHere) data.insert(p);
    }

    cout << data.size() << endl;

    return 0;
}