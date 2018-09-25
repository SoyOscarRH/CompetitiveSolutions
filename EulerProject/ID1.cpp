#include <iostream>
#include <vector>

using namespace std;


template <typename T>
T countMultiples(vector<T> tests, T limit) {
    T count {};
    for (T number = 1; number < limit; number++) {
        for (T test = 0; test < tests.size(); test++) {
            if (tests[test] and number % tests[test] == 0) {
                count += number;
                cout << number << endl;
                break;
            } 
        }
    }

    return count;
    
}

int main () {

    cout << "\n" << countMultiples<uint64_t>({3, 5, 8}, 1000) << endl;

    return 0;
}