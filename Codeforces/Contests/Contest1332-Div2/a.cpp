#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto inline in_range(num val, num x1, num x2) {
  return (x1 <= val and val <= x2);
}

auto solve() {
  num a, b, c, d;
  num x, y, x1, y1, x2, y2;
  cin >> a >> b >> c >> d;
  cin >> x >> y;
  cin >> x1 >> y1;
  cin >> x2 >> y2;


  if (
    in_range(x + b - a, x1, x2) and 
    (
      in_range(x + 1, x1, x2) 
      or
      in_range(x - 1, x1, x2) 
      or (a == 0 and b == 0)
    )
  ) {
    if (
    in_range(y + d - c, y1, y2) and 
      (
        in_range(y + 1, y1, y2) 
        or
        in_range(y - 1, y1, y2) 
        or (c == 0 and d == 0)
      )
    )

    return "Yes";
  }
  

  return "No";

}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  num tests;
  cin >> tests;

  while (tests--) {
    cout << solve() << endline;
  }

  return 0;
}