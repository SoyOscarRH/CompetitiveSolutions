class Solution {
 public:
  auto findComplement(int num) -> int {
    auto result = bitset<32> {};
    for (auto i = 0; num; ++i) {
      const auto bit_on = num bitand 1;
      result[i] = bit_on ? 0 : 1;
      num = num >> 1;
    }

    return result.to_ulong();
  }
};