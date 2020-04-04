class Solution {
 public:
  auto maxSubArray(const vector<int>& nums) -> int {
    auto sum = *max_element(begin(nums), end(nums));
    auto current = 0;
    for (const auto num : nums) {
      current += num;
      if (current > sum) sum = current;
      if (current < 0) current = 0;
    }

    return sum;
  }
};