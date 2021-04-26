#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto solve() -> int {
  int n;
  cin >> n;

  auto nums = vector<int>(n);
  for (auto& num : nums) { cin >> num; }

  const auto times = count(cbegin(nums), cend(nums), nums.front());
  if (times == 1) { return 0; }

  const auto x = find_if(cbegin(nums), cend(nums), [&](auto x) { return x != nums.front(); });
  return distance(cbegin(nums), x);
}

auto main() -> int {
  int test_cases;
  cin >> test_cases;

  while (test_cases--) { cout << 1 + solve() << "\n"; }

  return 0;
}