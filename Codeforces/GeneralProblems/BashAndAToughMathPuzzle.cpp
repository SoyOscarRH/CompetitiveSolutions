#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
struct segment_tree {
 private:
  using node = int;
  const int n;
  const T neutral;
  T (*fn)(T, T);
  vector<T> nodes;
  void build(const vector<T>& data, int begin, int end, node current) {
    if (begin == end) {
      nodes[current] = data[begin];
      return;
    }
    auto middle = (begin + end) / 2;
    build(data, begin, middle, current * 2 + 1);
    build(data, middle + 1, end, current * 2 + 2);
    nodes[current] = fn(nodes[current * 2 + 1], nodes[current * 2 + 2]);
  }

  int query(int begin, int end, node current, int left, int right, T value, int& changes) {
    if (changes > 1) return 0;
    if (end < left or right < begin) return 0;

    if (begin >= left and end <= right) {
      if (current < 4 * n and nodes[current] % value == 0) return 0;
    }

    if (begin == end) { changes++; return 1; }

    auto middle = (begin + end) / 2;
    const auto l = query(begin, middle, current * 2 + 1, left, right, value, changes);
    const auto r = query(middle + 1, end, current * 2 + 2, left, right, value, changes);

    return l + r;
  }

  void update(int begin, int end, node current, int index, const T val) {
    if (end < index or index < begin) return;
    if (begin == index and end == index) {
      nodes[current] = val;
      do {
        current = (current - 1) / 2;
        nodes[current] = fn(nodes[current * 2 + 1], nodes[current * 2 + 2]);
      } while (current != 0);
      return;
    }
    auto middle = (begin + end) / 2;
    update(begin, middle, current * 2 + 1, index, val);
    update(middle + 1, end, current * 2 + 2, index, val);
  }

 public:
  segment_tree(int n, T fn(T, T), T neutral)
      : nodes(4 * n, neutral), n(n), fn(fn), neutral(neutral) {}
  void build(const vector<T>& data) { build(data, 0, n - 1, 0); }
  void update(int index, const T& val) { update(0, n - 1, 0, index, val); }

  bool query(int left, int right, T value) {
    auto changes = 0;
    query(0, n - 1, 0, left, right, value, changes);
    return changes < 2;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, query;
  cin >> n;

  auto v = vector<int>(n);
  for (auto& x : v) cin >> x;

  segment_tree<int> s {n, gcd<int, int>, 0};
  s.build(v);

  cin >> query;

  while (query--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      cout << (s.query(l - 1, r - 1, x) ? "YES" : "NO") << "\n";
    } else {
      int i, y;
      cin >> i >> y;
      s.update(i - 1, y);
    }
  }

  return 0;
}