class Solution {
 public:
  auto binaryGap(int n) -> int {
    bitset<32> bits(n);
    auto last = -1, ans = 0;

    for (auto i = 0; i < 32; ++i) {
      if (bits[i]) {
        ans = last == -1 ? 0 : max(ans, i - last);
        last = i;
      }
    }

    return ans;
  }
};