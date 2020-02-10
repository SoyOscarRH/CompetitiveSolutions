class Solution {
 public:
  using matrix = vector<vector<int>>;
  matrix flipAndInvertImage(matrix A) {
    const auto rows = A.size(), cols = A[0].size();
    auto result = matrix(rows, vector<int>(cols));

    for (auto i = 0; i < rows; ++i) {
      for (auto j = 0; j < cols; ++j) {
        result[i][j] = not A[i][cols - 1 - j];
      }
    }

    return result;
  }
};