#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using num = int64_t;
constexpr auto endline = '\n';

auto is_possible() -> bool {
  auto n = 0, k = 0;
  cin >> n >> k;

  auto seen = unordered_map<int, int> {};
  auto buffer = num {};
  for (auto i = 0; i < n; i++) {
    cin >> buffer;
    ++seen[buffer];
  }

  for (auto i = 0; i < n; i++) {
    cin >> buffer;
    --seen[buffer];
  }

  auto different = vector<num> {};
  for (const auto& [value, times_seen] : seen)
    if (times_seen) different.push_back(value);

  auto const elements = different.size();
  if (not elements) return true;

  return elements == 2 and abs(different[0] - different[1]) <= k;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto test_cases = 0;
  cin >> test_cases;

  for (auto i = 0; i < test_cases; i++) {
    cout << (is_possible() ? "YES" : "NO") << endline;
  }

  return 0;
}