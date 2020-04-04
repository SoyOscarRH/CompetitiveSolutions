#include <iostream>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

int m[101][101];
int n;

auto read() -> void {
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }
}

auto repeat(bool row, int line) {
  auto seen = vector<bool>(n + 2, false);
  for (auto i = 0; i < n; ++i) {
    const auto x = row ? m[line][i] : m[i][line];
    if (seen[x]) return true;
    seen[x] = true;
  }

  return false;
}

auto solve(const int numcase) -> void {
  read();

  int trace = 0;
  for (auto i = 0; i < n; ++i) trace += m[i][i];

  int rows = 0;
  for (auto i = 0; i < n; ++i) rows += repeat(true, i);

  int cols = 0;
  for (auto i = 0; i < n; ++i) cols += repeat(false, i);

  cout << "Case #" << numcase << ": " << trace << " " << rows << " " << cols
       << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto tests = 10;
  cin >> tests;
  int i = 0;

  while (tests--) solve(++i);

  return 0;
}