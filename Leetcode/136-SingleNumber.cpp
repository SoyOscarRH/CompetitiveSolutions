class Solution {
 public:
  auto singleNumber(const vector<int>& nums) -> int {
    return accumulate(begin(nums), end(nums), 0, bit_xor<int> {});
  }
};