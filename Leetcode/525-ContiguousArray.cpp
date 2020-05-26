struct Solution {
  auto findMaxLength(const vector<int>& nums) -> int {
    auto memo = unordered_map<int, int> {};
    auto longest_contiguous = 0, sum = 0;
    for (auto i = 0; i < nums.size(); ++i) {
      sum += (nums[i] == 0) ? -1 : 1;
      if (sum == 0) {
        longest_contiguous = max(longest_contiguous, i + 1);
        continue;
      }

      auto it = memo.find(sum);
      if (it == end(memo)) {
        memo[sum] = i;
        continue;
      }

      const auto [_, start] = *it;
      longest_contiguous = max(longest_contiguous, i - start);
    }

    return longest_contiguous;
  }
};
