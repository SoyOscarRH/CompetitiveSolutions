#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

using namespace std;

auto is_possible(const array<int, 101>& food_type, const int num_days,
                 int participants) {
  for (auto i = 0; participants > 0; i++) {
    auto possible_people_than_can_eat = food_type[i] / num_days;
    if (not possible_people_than_can_eat) break;

    participants -= possible_people_than_can_eat;
  }

  return participants <= 0;
}

auto find_max(const array<int, 101>& food_type, int max_days,
              const int num_participantes) {
  auto l = 0, r = max_days;
  while (l <= r) {
    if (l == r) return l;

    int m = l + (r - l) / 2;
    if (l + 1 == r) ++m;

    if (is_possible(food_type, m, num_participantes)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return 0;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto num_participantes = 0;
  cin >> num_participantes;

  auto num_daily_food = 0;
  cin >> num_daily_food;

  array<int, 101> food_type {};

  for (auto i = 0; i < num_daily_food; i++) {
    auto data = 0;
    cin >> data;
    ++food_type[data];
  }

  sort(begin(food_type), end(food_type), greater<int>());

  auto num_days_max = 1;
  while (is_possible(food_type, num_days_max, num_participantes)) {
    num_days_max = num_days_max << 1;
  }

  cout << find_max(food_type, num_days_max, num_participantes) << endl;

  return 0;
}