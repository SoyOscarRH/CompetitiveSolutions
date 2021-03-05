#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve() -> int {
  int num_boxes;
  cin >> num_boxes;

  auto boxes = vector<int>(num_boxes);
  for (auto& box : boxes) cin >> box;

  auto balance = 100;
  auto max_balance = balance;

  for (auto& box : boxes) {
    balance += box;
    max_balance = max(max_balance, balance);
  }

  return max_balance;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout << solve() << endline;

  return 0;
}