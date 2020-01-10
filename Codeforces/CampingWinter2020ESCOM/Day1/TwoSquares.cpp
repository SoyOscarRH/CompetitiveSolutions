#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ld = long double;

template <typename number>
struct point {
  number x, y;

  point(number x = 0, number y = 0) : x {x}, y {y} {}

  point operator+(const point& p) const { return {x + p.x, y + p.y}; }
  point operator-(const point& p) const { return {x - p.x, y - p.y}; }
  point operator*(number k) const { return {x * k, y * k}; }
  point operator/(number k) const { return {x / k, y / k}; }

  friend std::istream& operator>>(std::istream& is, point& p) {
    return is >> p.x >> p.y;
  }
};

auto main() -> int {
  auto const n = 4;
  auto square = vector<point<ld>>(n);
  for (auto& point : square) cin >> point;

  auto result = ld {};
  for (auto i = 0; i < n; i++) {
  }

  cout << result << endl;

  return 0;
}