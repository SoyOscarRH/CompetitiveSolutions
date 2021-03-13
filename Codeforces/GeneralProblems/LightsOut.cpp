#include <array>
#include <iostream>

using namespace std;
using matrix = array<array<int, 3>, 3>;

auto main() -> int {
  const auto on = 1, off = 0;
  auto lights = matrix {{
      {on, on, on},
      {on, on, on},
      {on, on, on},
  }};

  auto times_pressed = matrix {};
  for (auto& line : times_pressed) {
    for (auto& element : line) { cin >> element; }
  }

  const auto invert = [](int& light) { light = light == on ? off : on; };
  const auto is_valid = [](int i, int j) { return (i >= 0 and i < 3) and (j >= 0 and j < 3); };

  const auto check_and_invert = [&](int i, int j) {
    if (is_valid(i, j)) { invert(lights[i][j]); }
  };

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) {
      if (times_pressed[i][j] % 2 == 1) {
        check_and_invert(i, j);
        check_and_invert(i + 1, j);
        check_and_invert(i - 1, j);
        check_and_invert(i, j + 1);
        check_and_invert(i, j - 1);
      }
    }
  }

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) { cout << lights[i][j]; }
    cout << endl;
  }

  return 0;
}
