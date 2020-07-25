#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  int64_t a, b, c, d, h;
  cin >> a >> b >> c >> d >> h;

  auto nums = vector<int64_t> {a, b, c, d};
  sort(begin(nums), end(nums));
  const auto possible = nums[1] + nums[2] + nums[3] >= h;

  cout << (not possible ? "AWW" : "WAW") << endl;

  return 0;
}