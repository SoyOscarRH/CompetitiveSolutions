struct Solution {
  using line = vector<vector<int>>;
  auto intervalIntersection(const line& A, const line& B) -> line {
    auto result = line {};
    int i = 0, j = 0;

    while (i < A.size() and j < B.size()) {
      auto l = max(A[i][0], B[j][0]);
      auto u = min(A[i][1], B[j][1]);
      if (l <= u) result.push_back({l, u});

      if (A[i][1] < B[j][1]) i++;
      else j++;
    }

    return result;
  }
};