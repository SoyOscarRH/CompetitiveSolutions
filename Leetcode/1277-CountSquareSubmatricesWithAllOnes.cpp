struct Solution {
  auto countSquares(vector<vector<int>>& matrix) -> int {
    auto squares = 0;
    auto n = static_cast<int>(matrix.size());
    auto m = static_cast<int>(matrix[0].size());

    for (auto i = 0; i < m; ++i) squares += matrix[n - 1][i];
    for (auto i = 0; i < n; ++i) squares += matrix[i][m - 1];
    squares -= matrix[n - 1][m - 1];

    for (auto i = n - 2; i >= 0; --i) {
      for (auto j = m - 2; j >= 0; --j) {
        matrix[i][j] = matrix[i][j] == 1
                           ? 1 + min({matrix[i + 1][j + 1], 
                                      matrix[i][j + 1],
                                      matrix[i + 1][j]})
                           : 0;

        squares += matrix[i][j];
      }
    }
    return squares;
  }
};