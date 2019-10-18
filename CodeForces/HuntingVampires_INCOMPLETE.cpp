#include <array>
#include <iostream>
#include <vector>

using namespace std;

char grid[2002][2002] = {'.'};
bool visited[2002][2002] = {false};

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
    for (int j = 1; j <= W; j++) {
      const auto left = j + 1, right = j - 1;
      const auto up = i - 1, down = i + 1;

      if (grid[i][j] != '*') continue;
      if (visited[i][j]) continue;

      if (grid[up][j] != '*' or grid[i][right] != '*' or grid[down][j] != '*' or
          grid[i][left] != '*')
        continue;

      auto exit_this = false;
      auto current = 0;

      auto num_arriba = 0;
      current = i - num_arriba - 1;

      while (grid[current][j] == '*') {
        if (visited[i][j]) continue;

        if (grid[current][left] == '*' or grid[current][right] == '*')
          exit_this = true;

        visited[current][j] = true;
        visited[current][left] = true;
        visited[current][right] = true;

        --current;
        ++num_arriba;
      }

      if (exit_this) continue;

      auto num_abajo = 0;
      current = i + num_abajo + 1;

      while (grid[current][j] == '*') {
        if (visited[i][j]) continue;

        if (grid[current][left] == '*' or grid[current][right] == '*')
          exit_this = true;

        visited[current][j] = true;
        visited[current][left] = true;
        visited[current][right] = true;

        ++current;
        ++num_abajo;
      }

      if (exit_this) continue;

      auto num_derecha = 0;
      current = j + num_derecha + 1;

      while (grid[i][current] == '*') {
        if (visited[i][j]) continue;

        if (grid[up][current] == '*' or grid[down][current] == '*' or
            num_derecha > num_arriba)
          exit_this = true;

        visited[i][current] = true;
        visited[down][current] = true;
        visited[up][current] = true;

        ++num_derecha;
        ++current;
      }

      if (exit_this) continue;

      auto num_izquierda = 0;
      current = j - num_izquierda - 1;

      while (grid[i][current] == '*') {
        if (visited[i][j]) continue;

        if (grid[up][current] == '*' or grid[down][current] == '*' or
            num_izquierda > num_arriba or num_izquierda > num_derecha)
          exit_this = true;

        visited[i][current] = true;
        visited[down][current] = true;
        visited[up][current] = true;

        --current;
        ++num_izquierda;
      }

      if (exit_this) continue;

      if (num_arriba == num_derecha and num_derecha == num_izquierda) {
        if (num_abajo > num_arriba) ++ans;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}