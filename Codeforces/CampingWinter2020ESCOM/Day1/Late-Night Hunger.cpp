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

template <typename T>
auto cross(const point<T>& p, const point<T>& q) -> T {
  return {p.x * q.y - p.y * q.x};
}

template <typename T>
auto area(const point<T>& a, const point<T>& b, const point<T>& c) -> T {
  const auto ab = b - a, ac = c - a;
  return 0.5 * cross(ab, ac);
}

auto main() -> int {
  auto n = 0;
  cin >> n;

  auto points = vector<point<ld>>(n);
  for (auto& point : points) cin >> point;

  auto result = ld {};
  for (auto i = 0; i < n; i++) {
    const auto x = i, y = (i + 1) % n, z = (i + 2) % n;
    result = max(result, area(points[x], points[y], points[z]));
  }

  cout << result << endl;

  return 0;
}