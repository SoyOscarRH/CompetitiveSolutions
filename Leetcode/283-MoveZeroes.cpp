#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    int numZeros {};
    size_t index {};

    for (int num : nums) {
      if (num == 0)
        ++numZeros;
      else
        nums[index++] = num;
    }

    index = nums.size();
    for (int i {}; i < numZeros; ++i) nums[--index] = 0;
  }
};