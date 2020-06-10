struct Solution {
  auto searchInsert(const vector<int>& nums, const int target) -> int {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      const auto mid = l + (r - l) / 2;
      if (nums[mid] < target) l = mid + 1;
      else r = mid - 1;
    }

    return l;
  }
};