#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto solve() -> int {
  auto num_elements = 0;
  cin >> num_elements;

  auto numbers = vector<int>(num_elements);
  for (auto& num : numbers) cin >> num;

  sort(begin(numbers), end(numbers));

  for (auto i = 1; i < num_elements; ++i) {
    if (numbers[i] == numbers[i - 1] + 1) {
      return 2;
    }
  }

  return 1;
}

auto main() -> int {

  // No merge cin/cout with scanf/printf
  ios::sync_with_stdio(false);

  // This unties cin from cout
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto test_cases = 0;
  cin >> test_cases;

  while (test_cases--) {
    cout << solve() << '\n';
  }

  return 0;
}
