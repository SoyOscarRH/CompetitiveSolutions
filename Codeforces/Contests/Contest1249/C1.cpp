#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

array<const int, 10> powers = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683};

auto generate_perfect(unsigned int n) {
  auto power = 0;

  auto result = 0;

  while (n) {
    if (n & 1) {
      result += powers[power];
    }
    n >>= 1;
    ++power;
  }

  return result;
}

auto generate_perfects() {
  auto numbers = vector<int>();
  numbers.reserve(256);

  for (auto i = 1; i < 513; ++i) numbers.push_back(generate_perfect(i));

  sort(begin(numbers), end(numbers));

  return numbers;
}

auto solve(vector<int>& perfects) -> int {
  auto number = 0;
  cin >> number;

  if (binary_search(begin(perfects), end(perfects), number)) {
    return number;
  }

  return *upper_bound(begin(perfects), end(perfects), number);
}

auto main() -> int {
  ios::sync_with_stdio(false);

  cin.tie(nullptr);
  cout.tie(nullptr);

  auto perfects = generate_perfects();

  auto test_cases = 0;
  cin >> test_cases;

  while (test_cases--) {
    cout << solve(perfects) << '\n';
  }

  return 0;
}
