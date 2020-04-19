#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

#include <stdio.h>
#include <string.h>

using namespace std;
constexpr auto endline = '\n';

using f64 = float;

struct point {
  unsigned short int x, y;
};

auto to_hash(int x, int y) { return (x * 301) + y; }

f64 m[301][301];

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  int W, H, L, U, R, D;
  cin >> W >> H >> L >> U >> R >> D;
  --L;
  --U;
  --R;
  --D;
  const auto is_in_void = [=](int x, int y) {
    if (L <= x and x <= R)
      if (U <= y and y <= D) return true;

    return false;
  };

  memset(m, 0.0, sizeof(m));

  constexpr unsigned short one = 1;

  m[0][0] = 1.0;
  auto to_visit = queue<point> {{{0, 0}}};
  auto already = unordered_set<int> {};
  already.insert(to_hash(0, 0));

  while (not to_visit.empty()) {
    const auto p = to_visit.front();
    const unsigned short x = p.x, y = p.y;
    const unsigned short x1 = x + 1, y1 = y + 1;

    to_visit.pop();
    if (x == W - 1 and y == H - 1) continue;
    if (is_in_void(x, y)) continue;
    const auto probability = m[x][y];
    m[x][y] = 0;

    if (x == W - 1) {
      m[x][y + 1] += probability;
      if (already.find(to_hash(x, y1)) == already.end()) {
        already.insert(to_hash(x, y1));
        to_visit.push({x, y1});
      }
    } else if (y == H - 1) {
      m[x + 1][y] += probability;
      if (already.find(to_hash(x1, y)) == already.end()) {
        to_visit.push({x1, y});
        already.insert(to_hash(x1, y));
      }
    } else {
      m[x + 1][y] += probability / 2;
      if (already.find(to_hash(x1, y)) == already.end()) {
        to_visit.push({x1, y});
        already.insert(to_hash(x1, y));
      }

      m[x][y + 1] += probability / 2;
      if (already.find(to_hash(x, y1)) == already.end()) {
        to_visit.push({x, y1});
        already.insert(to_hash(x, y1));
      }
    }
  }

  cout << m[W - 1][H - 1] << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto test = 1; test <= tests; ++test) solve(test);

  return 0;
}