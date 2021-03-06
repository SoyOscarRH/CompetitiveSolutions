#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  auto temperature_at = vector<int>(n);
  for (auto& t : temperature_at) cin >> t;

  auto max_temperature = INT32_MAX;
  auto day_to_start = 1;
  for (auto today = 0; today + 2 < n; ++today) {
    auto temperature_if_starting_today = max(temperature_at[today], temperature_at[today + 2]);
    if (temperature_if_starting_today < max_temperature) {
      max_temperature = temperature_if_starting_today;
      day_to_start = today + 1;
    }
  }

  cout << day_to_start << " " << max_temperature << endl;

  return 0;
}