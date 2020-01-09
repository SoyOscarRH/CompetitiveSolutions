//@see https://vjudge.net/problem/Gym-101466B

#include <vector>
#include <iostream>
#include <cstdint>

int main() {
    using namespace std;

    int64_t numChildren, x;
    cin >> numChildren;
    vector<int64_t> children (numChildren);

    for (int i = 0; i < numChildren; i++) {
        cin >> x;
        children[i] = x * -1;
    }

    sort(children.begin(), children.end());

    int64_t result {}, lastLevel {1}, thisLevel;
    for (auto child : children) {
        thisLevel = lastLevel * (child * -1);
        result += thisLevel;
        lastLevel = thisLevel;
    }

    cout << result + 1 << endl;

    return 0;
}