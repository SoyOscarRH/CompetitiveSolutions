struct Solution {
  auto reverseBits(uint32_t n) -> uint32_t {
    auto result = uint32_t {};

    for (auto i = 31; i >= 0; --i, n >>= 1) {
      if (n bitand 1) result = result bitor 1 << i;
    }

    return result;
  }
};