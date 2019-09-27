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

    auto num_towers = 0;
    cin >> num_towers;
    while (num_towers--) {
      auto i = 0, j = 0;
      cin >> i >> j;

      solution = solution xor (j - i - 1);
    }
    cout << "Case " << test << ": " << (solution ? "Alice" : "Bob") << '\n';
  }

  return 0;
}
