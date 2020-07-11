struct Solution {
  auto get_set(const vector<int>& nums, const long id) -> vector<int> {
    auto result = vector<int> {};
    auto bits = bitset<32> {id};

    for (auto i = 0; i < nums.size(); ++i)
      if (bits[i]) result.push_back(nums[i]);
  }

  auto subsets(const vector<int>& nums) -> vector<vector<int>> {
    auto result = vector<vector<int>> {};
    for (auto i = 0l; i < 1 << nums.size(); ++i) result.emplace_back(get_set(nums, i));

    return result;
  }
};