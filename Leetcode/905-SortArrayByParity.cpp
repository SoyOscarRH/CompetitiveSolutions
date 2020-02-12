class Solution {
 public:
  auto sortArrayByParity(vector<int> nums) -> vector<int> {
    auto even = [](int i) { return (i % 2) != 1; };
    partition(begin(nums), end(nums), even);

    return nums;
  }
};