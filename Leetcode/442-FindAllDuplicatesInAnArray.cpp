struct Solution {
  auto findDuplicates(const vector<int>& nums) -> vector<int> {
    auto duplicates = vector<int> {};

    for (const auto num : nums) {
      const auto index = abs(num) - 1;
      if (nums[index] < 0) duplicates.push_back(abs(index + 1));
      nums[index] = -nums[index];
    }

    return duplicates;
  }
};