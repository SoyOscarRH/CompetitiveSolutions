#include <algorithm>
#include <array>
#include <iostream>
#include <string>

auto main() -> int {
  using namespace std;

  array<array<int, 3>, 3> times_pressed;

  for (auto& line : times_pressed) {
    for (auto& element : line) { cin >> element; }
  }

  array<array<int, 3>, 3> lights = {{
      {1, 1, 1},
      {1, 1, 1},
      {1, 1, 1},
  }};

  const auto invert = [](int& x) { x = x == 0 ? 1 : 0; };

  const auto is_valid = [](const int i, const int j) {
    return (i >= 0 and i < 3) and (j >= 0 and j < 3);
  };

  const auto checkAndInvert = [&](const int i, const int j) {
    if (is_valid(i, j)) invert(lights[i][j]);
  };

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) {
      const auto num_pressed = times_pressed[i][j];
      for (auto time = 0; time < num_pressed; ++time) {
        checkAndInvert(i, j);
        checkAndInvert(i + 1, j);
        checkAndInvert(i - 1, j);
        checkAndInvert(i, j + 1);
        checkAndInvert(i, j - 1);
      }
    }
  }

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) { cout << lights[i][j]; }
    cout << endl;
  }

  return 0;
}
