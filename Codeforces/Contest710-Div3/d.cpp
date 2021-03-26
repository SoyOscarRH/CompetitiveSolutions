#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

auto solve(const vector<int>& nums) -> int {
  auto times_seen = map<int, int, greater<int>> {};
  for (auto x : nums) { ++times_seen[x]; }

  auto frecuencies = vector<int> {};
  for (const auto& entry : times_seen) { frecuencies.push_back(entry.second); }

  while (frecuencies.size() > 1) {
    const auto t1 = frecuencies.back();
    frecuencies.pop_back();
    const auto t2 = frecuencies.back();
    frecuencies.pop_back();

    frecuencies.push_back(abs(t1 - t2));
  }

  return frecuencies.back();
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    auto nums = vector<int>(n);
    for (auto& x : nums) { cin >> x; }
    cout << solve(nums) << endl;
  }

  return 0;
}