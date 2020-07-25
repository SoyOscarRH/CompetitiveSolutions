#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num_t = uint64_t;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  num_t n;
  cin >> n;
  auto nums = vector<pair<string, vector<int>>>(n);
  for (auto& [num, bucket] : nums) {
    cin >> num;
    bucket = vector<int>(10, 0);
    for (auto l : num) { ++bucket[l - '0']; }
    num.clear();
    for (auto i = 9; i >= 0; --i) num.append(bucket[i], '0' + i);
  }

  sort(begin(nums), end(nums), [](const auto& x, const auto& y) {
    const auto option1 = x.first + y.first;
    const auto option2 = y.first + x.first;
    
    return option1 > option2;
  });

  for (const auto& num : nums) { cout << num.first; }
  cout << endl;

  return 0;
}