class Solution {
 public:
  auto majorityElement(vector<int>& nums) -> int {
    auto candidate = 0, frequency = 0;
    const auto acceptable = nums.size() / 2;
    
    for (auto num : nums) {
      if (frequency > acceptable) return candidate;
      if (frequency == 0) candidate = num, frequency = 1;
      else if (num == candidate) ++frequency;
      else --frequency;
    }
    
    return candidate;
  }
};