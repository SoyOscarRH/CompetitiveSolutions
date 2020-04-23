class Solution {
 public:
  auto rangeBitwiseAnd(int m, int n) -> int {
    auto i = 0;
    for (; m != n; ++i) m /= 2, n /= 2;

    return m << i;
  }
};
