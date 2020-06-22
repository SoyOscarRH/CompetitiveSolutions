struct Solution {
  auto singleNumber(const vector<int>& nums) -> int {
    auto b0 = 0, b1 = 0, reset = 0;
    for (const auto num : nums) {
      b1 = b1 bitor (b0 bitand num);
      b0 = b0 xor num;
      reset = b1 bitand b0;
      b1 = b1 xor reset;
      b0 = b0 xor reset;
    }

    return b0;
  }
};