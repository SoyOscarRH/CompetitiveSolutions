#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
using num = long long;
using unum = unsigned long long;

constexpr auto endline = '\n';

auto sum(const vector<num>& v) -> unum {
  auto sum = unum {0};
  for (auto x : v) { sum += x; }

  return sum;
}

auto min_non_zero(vector<num>& performances) -> void {
  num min_non_zero = INT32_MAX;
  for (const auto x : performances) {
    if (x == 0) continue;
    min_non_zero = min(min_non_zero, x);
  }

  for (auto& x : performances) {
    if (x == min_non_zero) x = 1;
  }
}

auto solve(vector<num>& performances) -> vector<num> {
  const auto n = num(performances.size());

  min_non_zero(performances);

  const auto left = [&](const num i) { return i != 0 ? i - 1 : n - 1; };
  const auto right = [&](const num i) { return i != (n - 1) ? i + 1 : 0; };

  const auto my_bonus = [&](vector<num>& bonus, const num me) -> void {
    const auto my_left_bonus = bonus[left(me)];
    const auto my_right_bonus = bonus[right(me)];
    const auto my_bonus = bonus[me];

    const auto my_left_perf = performances[left(me)];
    const auto my_right_perf = performances[right(me)];
    const auto my_perf = performances[me];

    if (my_bonus < 2) { return; }

    if (my_perf != my_left_perf and my_perf != my_right_perf and my_left_perf != my_right_perf) {
      const auto min_perf = min({my_perf, my_left_perf, my_right_perf});
      if (min_perf == my_perf) {
        bonus[me] = 1;
        return;
      }

      const auto max_perf = max({my_perf, my_left_perf, my_right_perf});
      if (max_perf == my_perf) {
        bonus[me] = 1 + max({my_left_bonus, my_right_bonus});
        return;
      }

      bonus[me] = 1 + min({my_left_bonus, my_right_bonus});
      return;
    }

    if (my_left_perf == my_right_perf) {
      const auto bigger = my_left_perf < my_perf;
      if (bigger) {
        bonus[me] = 1 + max({my_left_bonus, my_right_bonus});
        return;
      }

      const auto smaller = my_left_perf > my_perf;
      if (smaller) {
        bonus[me] = 1;
        return;
      }
    }

    if (my_perf == my_left_perf) {
      bonus[me] = my_left_bonus;
      return;
    }

    bonus[me] = 1 + min({my_left_bonus});
  };

  auto bonus_left = performances;
  for (auto i = 0; i < n; ++i) { my_bonus(bonus_left, i); }
  for (auto i = 0; i < n; ++i) { my_bonus(bonus_left, i); }

  auto bonus_right = performances;
  for (auto i = n - 1; i >= 0; --i) { my_bonus(bonus_right, i); }
  for (auto i = n - 1; i >= 0; --i) { my_bonus(bonus_right, i); }

  return sum(bonus_left) < sum(bonus_right) ? bonus_left : bonus_right;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  num n, b;
  cin >> n >> b;

  auto performances = vector<num>(n);
  for (auto& performance : performances) cin >> performance;

  const auto min_performances = solve(performances);
  for (const auto min_performance : min_performances) { cout << min_performance * b << " "; }
  cout << endl;

  return 0;
}