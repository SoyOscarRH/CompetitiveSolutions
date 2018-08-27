#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


pair<bool, double> findSolution(double p, double q, double r, double s, double t, double u) {

    auto evaluate = [&](double x) -> double {
        return (p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u);
    };

    if (evaluate(0) * evaluate(1) > 0) return {false, 0.0f};

    double left = 0, right = 1;
    bool first_is_negative = evaluate(0) < 0;

    for (int i = 0; i < 100; i++) {
        double middle = (left + right) / 2;
        double middle_result = evaluate(middle);
        
        if (first_is_negative) {
            if (middle_result < 0) left = middle;
            else right = middle;
        }
        else {
            if (middle_result < 0) right = middle;
            else left = middle;                        
        }
    }

    return {true, left};
};


int main () {

    double p, q, r, s, t, u;

    while (cin >> p >> q >> r >> s >> t >> u) {

        auto solution = findSolution(p, q, r, s, t, u);
        if (solution.first) cout << setprecision(4) << fixed << solution.second << endl;
        else cout << "No solution" << endl;
    }

    return 0;
}

