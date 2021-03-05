#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto main() -> int {
  ios::sync_with_stdio(false);

  num n, m, buffer;
  cin >> n >> m;

  auto bowls = list<num> {}, cups = list<num>(m);
  for (auto i = 0; i < n; ++i) {
    cin >> buffer;
    bowls.emplace_back(buffer);
  }

  for (auto i = 0; i < m; ++i) {
    cin >> buffer;
    cups.emplace_back(buffer);
  }

  auto waste = vector<num> {};
  while (!bowls.empty()) {
    if (cups.front() >= bowls.front()) {
      cups.front() -= bowls.front();
      bowls.pop_front();
    } else {
      waste.push_back(cups.front());
      cups.pop_front();
    }
  }

  for (const auto x : cups) { waste.push_back(x); }

  cout << accumulate(begin(waste), end(waste), 0) << endline;

  return 0;
}