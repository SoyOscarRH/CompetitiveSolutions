#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
struct segment_tree {
  const int n;
  const T neutral;
  T (*fn) (T, T);
  vector<T> nodes;
  segment_tree(int n, T fn(T, T), T neutral)
      : nodes(2 * n, neutral), n(n), fn(fn), neutral(neutral) {}

  auto build(const vector<T>& data) -> void {
    for (auto i = 0; i < data.size(); ++i) nodes[n + i] = data[i];
    for (auto i = n - 1; i > 0; --i) nodes[i] = fn(nodes[2 * i], nodes[2 * i + 1]);
  }

  auto update(const int p, const T value) -> void {
    nodes[n + p] = value;
    for (auto i = p + n; i > 1; i /= 2) nodes[i / 2] = fn(nodes[i xor 0], nodes[i xor 1]);
  }

  auto query(const int left, const int right) -> T const {
    auto result = neutral;
    for (auto l = left + n, r = right + n + 1; l < r; l /= 2, r /= 2) {
      if (l bitand 1) result = fn(result, nodes[l++]);
      if (r bitand 1) result = fn(result, nodes[--r]);
    }
    return result;
  }
};

using num = int64_t;
using p = pair<num, num>;

int main() {
  const auto f = [](const p a, const p b) -> p {
    auto v = vector<num> {a.first, a.second, b.first, b.second};
    sort(begin(v), end(v));
    return {v[3], v[2]};
  };

  int n, query;
  cin >> n;

  auto s = segment_tree<p> {n, f, {0, 0}};
  auto v = vector<num>(n);
  for (auto& x : v) cin >> x;

  cin >> query;

  auto v2 = vector<p> {};
  for (auto x : v) v2.push_back({x, 0});

  s.build(v2);

  while (query--) {
    int a, b;
    char q;
    cin >> q >> a >> b;

    if (q == 'U')
      s.update(a - 1, {b, 0});
    else {
      const auto x = s.query(a - 1, b - 1);
      cout << x.first + x.second << '\n';
    }
  }

  return 0;
}