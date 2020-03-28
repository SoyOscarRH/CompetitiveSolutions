#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using num = unsigned long long;
constexpr auto endline = '\n';

auto main() -> int {
  ios::sync_with_stdio(false);

  num cows_allow, num_farms, num_visits;
  cin >> cows_allow >> num_farms >> num_visits;

  auto farms = vector<num>(cows_allow + 1);
  for (num i = 0, buffer = 0; i < num_farms; ++i) {
    cin >> buffer;
    ++farms[buffer];
  }

  auto days = vector<int>(num_visits);
  for (auto& d : days) cin >> d;

  const auto last = days[days.size() - 1];
  for (auto i = 0, index = 0; i <= last; ++i) {
    if (i == days[index]) {
      cout << accumulate(begin(farms) + 1, end(farms), num{}) << endline;
      ++index;
    }

    auto farms_future = vector<num>(cows_allow + 1);

    for (num num_cows = 1; num_cows <= cows_allow; ++num_cows) {
      const auto num_farms_situation = farms[num_cows];
      if (num_farms_situation == 0) continue;

      const auto num_cows_future = 2 * num_cows;
      if (num_cows_future > cows_allow) {
        const auto cows_to_take = num_cows_future / 2;
        const auto to_leave = num_cows_future - cows_to_take;

        farms_future[cows_to_take] += num_farms_situation;
        farms_future[to_leave] += num_farms_situation;
      } else
        farms_future[num_cows_future] += num_farms_situation;
    }

    farms = std::move(farms_future);
  }

  return 0;
}