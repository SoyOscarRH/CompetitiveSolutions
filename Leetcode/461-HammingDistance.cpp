struct Solution {
  auto hammingDistance(const int x, const int y) -> int { return __builtin_popcount(x xor y); }
};

struct Solution {
  auto hammingDistance(const int x, const int y) -> int {
    auto different_bits = 0;
    auto result = x xor y;
    for (auto i = 0; i < sizeof(int) * 8; ++i) {
      if (result bitand 1 == 1) ++different_bits;
      result = result >> 1;
    }

    return different_bits;
  }
};