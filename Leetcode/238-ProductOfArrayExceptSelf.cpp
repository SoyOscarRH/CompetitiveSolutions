class Solution {
public:
    auto productExceptSelf(const vector<int>& nums) -> vector<int> {
      const auto n = nums.size();
      auto result = vector<int> (n, 1);
        
      auto left = 1;
      auto right = 1;
        
      for (auto i = 0; i < n; ++i) {
        result[i] *= left;
        result[n-1-i] *= right;
        
        left *= nums[i];
        right *= nums[n-1-i];
      }
      
      return result;
    }
};