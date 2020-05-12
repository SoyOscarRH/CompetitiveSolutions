class Solution {
 public:
  auto singleNonDuplicate(const vector<int>& nums) -> int {
    int start = 0, end = nums.size() - 1;

    while (start < end) {
      auto mid = start + (end - start) / 2;
      if (mid & 1) mid--;

      if (nums[mid] != nums[mid + 1]) end = mid;
      else start = mid + 2;
    }

    return nums[start];
  }
};