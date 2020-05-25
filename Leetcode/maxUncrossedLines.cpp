struct Solution {
  auto maxUncrossedLines(const vector<int>& A, const vector<int>& B) -> int {
    int m = A.size(), n = B.size();
    auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = A[i] == B[j] ? dp[i][j] + 1
                                        : max(dp[i][j + 1], dp[i + 1][j]);
      }
    }

    return dp[m][n];
  }
};