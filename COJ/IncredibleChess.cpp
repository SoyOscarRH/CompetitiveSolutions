#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  auto test_cases = 0;
  cin >> test_cases;

  for (int test = 1; test <= test_cases; ++test) {
    auto solution = 0;

    auto num_peons = 0;
    cin >> num_peons;

    auto b = vector<int>(num_peons);
    auto w = vector<int>(num_peons);

    for (auto& bi : b) cin >> bi;
    for (auto& wi : w) cin >> wi;

    for (int i = 0; i < num_peons; i++) {
      solution = solution xor (w[i] - b[i] - 1);
    }

    cout << "Case " << test << ": " << (solution == 0 ? "black" : "white") << " wins"
         << '\n';
  }

  return 0;
}
