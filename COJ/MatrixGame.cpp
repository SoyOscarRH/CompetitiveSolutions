#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  auto test_cases = 0;
  cin >> test_cases;

  for (int test = 1; test <= test_cases; ++test) {
    auto m = 0, n = 0;
    cin >> m >> n;
    auto solution = 0, temporal = 0;
    for (int i = 0; i < m; ++i) {
      auto partial_sum = 0;
      for (int j = 0; j < n; ++j) {
        cin >> temporal;
        partial_sum += temporal;
      }

      solution = solution xor partial_sum;
    }

    cout << "Case " << test << ": " << (solution ? "Alice" : "Bob") << '\n';
  }

  return 0;
}
