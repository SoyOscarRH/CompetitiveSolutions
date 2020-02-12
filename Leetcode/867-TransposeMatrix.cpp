class Solution {
 public:
  using matrix = vector<vector<int>>;
  
  auto transpose(const matrix& A) -> matrix {
    const auto rows = A.size(), cols = A[0].size();
    auto result = matrix(cols, vector<int>(rows));

    for (auto i = 0; i < rows; ++i) {
      for (auto j = 0; j < cols; ++j) {
        result[j][i] = A[i][j];
      }
    }

    return result;
  }
};