#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int_fast64_t;

struct point {
  num R, G, B, Y;
};

auto main() -> int {
  ios::sync_with_stdio(false);
  auto necklace = string {};
  cin >> necklace;

  auto from_zero_to_but_no = vector<point>(necklace.size() + 1);
  from_zero_to_but_no[0] = point {0, 0, 0, 0};
  for (auto i = 0; i < necklace.size(); ++i) {
    auto current = from_zero_to_but_no[i];
    if (necklace[i] == 'R') ++current.R;
    if (necklace[i] == 'G') ++current.G;
    if (necklace[i] == 'B') ++current.B;
    if (necklace[i] == 'Y') ++current.Y;
    from_zero_to_but_no[i + 1] = current;
  }

  // from [i, j]
  num diff = INT32_MAX;
  num size = 0;
  num better_i = 0, better_j = 0;

  for (auto i = 0; i < necklace.size(); ++i) {
    for (auto j = i; j < necklace.size(); ++j) {
      auto x = from_zero_to_but_no[j + 1];
      auto y = from_zero_to_but_no[i];

      auto [min_el, max_el] = minmax({
          abs(x.R - y.R),
          abs(x.G - y.G),
          abs(x.B - y.B),
          abs(x.Y - y.Y),
      });

      auto current_diff = max_el - min_el;
      const auto current_size = j - i + 1;
      const auto same_but_better = current_diff == diff and current_size > size;
      if (same_but_better or current_diff < diff) {
        diff = current_diff;
        size = current_size;
        better_i = i + 1;
        better_j = j + 1;
      }
    }
  }

  cout << diff << " " << size << endl;
  cout << better_i << " " << better_j << endl;

  return 0;
}