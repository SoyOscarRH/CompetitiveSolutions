#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto solve(const int h, const int w) -> double {
  auto matrix = vector<string>(h);
  for (auto& line : matrix) { cin >> line; };

  auto area = 0.0;
  auto inside = false;
  for (const auto& line : matrix) {
    for (const auto symbol : line) {
      const auto is_diagonal = symbol == '/' or symbol == '\\';
      if (inside and symbol == '.') { area += 1; }
      if (is_diagonal) {
        area += 0.5;
        inside = !inside;
      }
    }
  };

  return area;
}

int main() {
  int h, w;
  while (cin >> h >> w) { cout << solve(h, w) << endl; }

  return 0;
}