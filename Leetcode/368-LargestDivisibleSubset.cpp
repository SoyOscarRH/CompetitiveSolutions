struct Solution {
  auto largestDivisibleSubset(vector<int>& nums) -> vector<int> {
    const int n = nums.size();
    if (n == 0) return {};

    sort(begin(nums), end(nums));

    auto dp = vector<int>(n, 1);
    auto previous_index = vector<int>(n, -1);
    auto max_i = 0;

    for (auto i = 1; i < n; ++i) {
      for (auto j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          previous_index[i] = j;
        }
      }
      if (dp[i] > dp[max_i]) max_i = i;
    }

    auto answer = vector<int> {};
    for (auto i = max_i; i >= 0; i = previous_index[i]) answer.push_back(nums[i]);
    return answer;
  }
};