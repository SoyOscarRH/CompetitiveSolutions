class Solution {
 public:
  auto binarySearch(const vector<int>& nums, int low, int high, int key)
      -> int {
    if (high < low) return -1;
    auto mid = low + (high - low) / 2;

    if (key == nums[mid]) return mid;
    if (key > nums[mid]) return binarySearch(nums, (mid + 1), high, key);
    return binarySearch(nums, low, (mid - 1), key);
  }

  auto findPivotIndex(const vector<int>& nums, int low, int high) -> int {
    if (high < low) return -1;
    if (high == low) return low;

    int mid = low + (high - low) / 2;
    if (mid < high and nums[mid] > nums[mid + 1]) return mid;
    if (mid > low and nums[mid] < nums[mid - 1]) return (mid - 1);
    if (nums[low] >= nums[mid]) return findPivot(nums, low, mid - 1);

    return findPivot(nums, mid + 1, high);
  }

  auto search(const vector<int>& nums, int target) -> int {
    const auto n = nums.size();
    int pivot = findPivotIndex(nums, 0, n - 1);

    if (pivot == -1) return binarySearch(nums, 0, n - 1, target);
    if (nums[pivot] == target) return pivot;
    if (nums[0] <= target)
      return binarySearch(nums, 0, pivot - 1, target);
    else
      return binarySearch(nums, pivot + 1, n - 1, target);
  }
};