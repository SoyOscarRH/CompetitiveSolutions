

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

struct disjointSet {
  vector<int> parent;

  disjointSet(int n) : parent(n) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  void join(int a, int b) { parent[find(b)] = find(a); }

  int find(int a) { return a == parent[a] ? a : parent[a] = find(parent[a]); }

  bool check(int a, int b) { return find(a) == find(b); }
};

array<int, 11> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

auto solve() {
  int n;
  cin >> n;
  auto d = disjointSet(n + 1);

  auto v = vector<int>(n);
  for (auto& x : v) cin >> x;

  auto result = vector<int> {};

  for (auto num : v) {
    for (auto p : primes) {
      if (num % p != 0) continue;
      result.push_back(p);
      break;
    }
  }

  auto jaja = unordered_set<int> {begin(result), end(result)};
  cout << jaja.size() << endline;
  auto i = 0;
  auto trans = unordered_map<int, int> {};
  for (auto x : result)
    if (not trans[x]) trans[x] = ++i;

  for (auto i = 0; i < result.size(); i++) {
    cout << trans[result[i]];
    cout << " ";
  }

  cout << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;

  while (tests--) {
    solve();
  }

  return 0;
}