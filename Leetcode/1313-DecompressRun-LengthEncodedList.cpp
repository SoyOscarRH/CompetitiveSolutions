class Solution {
 public:
  auto decompressRLElist(vector<int>& nums) -> vector<int> {
    auto result = vector<int> {};
    for (auto i = 0; i < nums.size(); i += 2) {
      auto const frequency = nums[i], value = nums[i + 1];
      result.insert(end(result), frequency, value);
    }

    return result;
  }
};