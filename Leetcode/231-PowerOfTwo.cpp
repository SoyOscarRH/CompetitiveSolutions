class Solution {
 public:
  auto isPowerOfTwo(const int n) -> bool {
    if (n <= 0) return false;
    return (n bitand (n - 1)) == 0;
  }
};