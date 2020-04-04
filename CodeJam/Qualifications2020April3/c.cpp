#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

struct point {
  int start, end, index;
};

auto get_activities(const int many) -> vector<point> {
  auto activities = vector<point>(many);
  auto i = 0;
  for (auto& activity : activities) {
    cin >> activity.start >> activity.end;
    activity.index = i++;
  }

  sort(begin(activities), end(activities), [](const point& x, const point& y) {
    if (x.start != y.start) return x.start < y.start;
    return x.end < y.end;
  });
  return activities;
}

auto solve(const int testcase) -> void {
  cout << "Case #" << testcase << ": ";
  auto num_activities = 0;
  cin >> num_activities;

  auto result = string(num_activities, '_');

  auto free_time1 = 0, free_time2 = 0;
  const auto activities = get_activities(num_activities);

  for (const auto& time : activities) {
    const auto start = time.start, end = time.end;
    if (free_time1 <= start) {
      free_time1 = end;
      result[time.index] = 'C';
      continue;
    }

    if (free_time2 <= start) {
      free_time2 = end;
      result[time.index] = 'J';
      continue;
    }

    cout << "IMPOSSIBLE" << endline;
    return;
  }

  cout << result << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto i = 1; i <= tests; i++) solve(i);

  return 0;
}