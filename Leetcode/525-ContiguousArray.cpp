class Solution {
 public:
  auto findMaxLength(const vector<int>& nums) -> int {
    const auto n = nums.size();
    auto sum_considering = vector<int>(n + 1, 0);

    auto last_seen = unordered_map<int, int> {};
    for (auto i = 1; i <= n; ++i) {
      sum_considering[i] = sum_considering[i - 1] + (nums[i - 1] ? 1 : -1);
      last_seen[sum_considering[i]] = i;
    }

    auto result = 0;
    for (auto begin = 0; begin < n; ++begin) {
      const auto end = last_seen[sum_considering[begin]];
      const auto size = end - begin;
      if (size > result) result = size;
    }

    return result;
  }
};