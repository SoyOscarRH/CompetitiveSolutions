#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
using matrix = vector<vector<int>>;

template <typename T>
inline auto read() -> T {
  auto to_read = T {};
  cin >> to_read;
  return to_read;
}

auto solve() -> void {
  const auto rows = read<int>(), cols = read<int>();

  auto m = matrix<int>(rows, vector<int>(cols));

  for (auto i = 0; i < rows; ++i) {
    for (auto j = 0; j < cols; ++j) cin >> m[i][j];
  }

  const auto num_to_read = read<int>();
  auto reverse_row = false, reverse_col = false;

  for (auto i = 0; i < num_to_read; ++i) {
    const char move = read<char>();
    if (move == 'V')
      reverse_row = !reverse_row;
    else
      reverse_col = !reverse_col;
  }

  const auto limit_i = reverse_row ? -1 : rows;
  const auto update_i = reverse_row ? -1 : 1;
  const auto init_i = reverse_row ? rows - 1 : 0;

  const auto limit_j = reverse_col ? -1 : cols;
  const auto update_j = reverse_col ? -1 : 1;
  const auto init_j = reverse_col ? cols - 1 : 0;

  for (auto i = init_i; i != limit_i; i += update_i) {
    for (auto j = init_j; j != limit_j; j += update_j) {
      cout << m[i][j] << " ";
    }
    cout << '\n';
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}
