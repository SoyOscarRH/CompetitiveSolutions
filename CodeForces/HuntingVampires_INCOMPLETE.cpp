#include <array>
#include <iostream>
#include <vector>

using namespace std;

char grid[2002][2002] = {'.'};

int to_l[2002][2002] = {0};
int to_r[2002][2002] = {0};
int to_u[2002][2002] = {0};
int to_d[2002][2002] = {0};

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int H, W, ans = 0;
  cin >> H >> W;

  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) cin >> grid[i][j];
  }

  for (int i = 1; i <= H; ++i) {
    auto current = 0;
    for (int j = 1; j <= W; ++j) {
      to_r[i][j] = current;
      if (grid[i][j] == '*' and grid[i + 1][j] != '*' and grid[i - 1][j] != '*')
        ++current;
      else
        current = 0;
    }
  }

  for (int i = 1; i <= H; ++i) {
    auto current = 0;
    for (int j = W; j >= 1; --j) {
      to_l[i][j] = current;
      if (grid[i][j] == '*' and grid[i + 1][j] != '*' and grid[i - 1][j] != '*')
        ++current;
      else
        current = 0;
    }
  }

  for (int j = 1; j <= W; ++j) {
    auto current = 0;
    for (int i = 1; i <= H; ++i) {
      to_d[i][j] = current;
      if (grid[i][j] == '*' and grid[i][j + 1] != '*' and
          grid[i - 1][j - 1] != '*')
        ++current;
      else
        current = 0;
    }
  }

  for (int j = 1; j <= W; ++j) {
    auto current = 0;
    for (int i = H; i >= 1; --i) {
      to_u[i][j] = current;
      if (grid[i][j] == '*' and grid[i][j + 1] != '*' and
          grid[i - 1][j - 1] != '*')
        ++current;
      else
        current = 0;
    }
  }

  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; j++) {
      if (grid[i][j] != '*') continue;

      if (grid[i + 1][j] != '*' or grid[i][j + 1] != '*' or
          grid[i - 1][j] != '*' or grid[i][j - 1] != '*')
        continue;

      auto num_d = to_l[i][j + 1];
      auto num_i = to_r[i][j - 1];

      auto num_arriba = to_u[i - 1][j];
      auto num_abajo = to_d[i + 1][j];

      cout << i << endl
           << j << endl
           << num_d << endl
           << num_i << endl
           << num_arriba << endl
           << num_abajo << endl
           << endl;

      if (num_arriba == num_d and num_d == num_i) {
        if (num_abajo > num_arriba) ++ans;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}