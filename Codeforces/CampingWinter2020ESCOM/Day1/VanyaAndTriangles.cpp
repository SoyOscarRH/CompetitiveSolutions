#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

template <typename number>
struct point {
  number x, y;
  point(number x = 0, number y = 0) : x {x}, y {y} {}

  point operator+(const point& p) const { return {x + p.x, y + p.y}; }
  point operator-(const point& p) const { return {x - p.x, y - p.y}; }

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
  return cross(ab, ac);
}

auto main() -> int {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto n = 0;
  cin >> n;

  auto points = vector<point<int>>(n);
  for (auto& p : points) cin >> p;

  auto result = 0;

  for (auto i = 0; i < n; i++) {
    for (auto j = i + 1; j < n; j++) {
      for (auto k = j + 1; k < n; k++) {
        if (area(points[i], points[j], points[k])) ++result;
      }
    }
  }

  cout << result << endl;

  return 0;
}