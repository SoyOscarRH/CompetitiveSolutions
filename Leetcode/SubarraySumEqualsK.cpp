class Solution {
 public:
  auto subarraySum(const vector<int>& nums, const int k) -> int {
    const auto n = nums.size();
    auto sum_of_first = vector<int>(n + 1, 0);
    for (auto i = 0; i < n; ++i)
      sum_of_first[i + 1] = sum_of_first[i] + nums[i];

    auto options = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = i; j < n; ++j) {
        if (sum_of_first[j + 1] - sum_of_first[i] == k) ++options;
      }
    }

    return options;
  }
};