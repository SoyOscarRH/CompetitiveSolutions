#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  auto days = 0;
  cin >> days;

  auto result = vector<int>(days);

  for (auto i = 0; i < days; ++i) {
    for (auto j = 0; j < days; ++j) {
      ++result[(i * j) % days];
    }
  }

  auto i = 0;
  for (auto x : result) {
    cout << i++ << ": " << x << '\n';
  };

  return 0;
}