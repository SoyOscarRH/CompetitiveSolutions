#include <algorithm>
#include <array>
#include <iostream>

auto main() -> int {
  using namespace std;

  enum class pixel : char { empty, fill };

  array<array<pixel, 100>, 5000> board;
  {
    array<pixel, 100> row;
    row.fill(pixel::empty);
    board.fill(row);
  }

  int base, num_rows;
  cin >> base >> num_rows;

  int max_height = 5000;
  for (auto i = 0; i < num_rows; ++i) {
    int horizontal, vertical, start_block;
    cin >> horizontal >> vertical >> start_block;

    --start_block;

    int current_height = 0;
    auto can_go_down = false;
    do {
      if (current_height == board.size()) break;
      auto start_pixel = begin(board[current_height++]) + start_block;
      can_go_down = all_of(start_pixel, start_pixel + horizontal,
                           [](const pixel x) { return x == pixel::empty; });
    } while (can_go_down);

    current_height -= 2;

    for (auto dv = 0; dv < vertical; ++dv) {
      for (auto dh = 0; dh < horizontal; ++dh) {
        board[current_height - dv][start_block + dh] = pixel::fill;
      }
    }
    max_height = min(max_height, current_height - vertical);
  }

  cout << 5000 - max_height - 2 << endl;

  return 0;
}