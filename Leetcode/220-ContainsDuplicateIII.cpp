struct Solution {
  using num = long long;
  auto containsNearbyAlmostDuplicate(const vector<int>& nums, const num k, const num t) -> bool {
    auto window = set<num> {};

    for (auto i = 0; i < nums.size(); i++) {
      if (i > k and (i - k - 1) < nums.size()) window.erase(nums[i - k - 1]);

      auto const position = window.lower_bound(nums[i] - t);
      if (position != cend(window) and (*position - nums[i]) <= t) return true;

      window.insert(nums[i]);
    }

    return false;
  }
};