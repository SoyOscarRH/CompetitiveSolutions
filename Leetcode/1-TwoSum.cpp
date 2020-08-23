struct Solution {
  auto twoSum(const vector<int>& nums, const int target) -> vector<int> {
    auto to_find = map<int, int> {};

    for (auto i = 0; i < nums.size(); ++i) {
      const auto num_to_find = target - nums[i];
      const auto already_seen = to_find.find(num_to_find) != end(to_find);
      if (already_seen) return {to_find[num_to_find], i};

      to_find[nums[i]] = i;
    }

    return {0, 0};
  }
};