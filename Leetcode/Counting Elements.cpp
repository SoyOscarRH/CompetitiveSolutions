class Solution {
 public:
  int countElements(vector<int>& arr) {
    const auto seen = unordered_set<int> {begin(arr), end(arr)};
    return count_if(cbegin(arr), cend(arr), [&](auto x) { return seen.count(x + 1); });
  }
};

class Solution {
 public:
  int countElements(vector<int>& nums) {
    const array<bool, 1002> seen {};
    for (const auto num : nums) seen[num] = true;
    return count_if(cbegin(nums), cend(nums), [&](const auto x) { return seen[x + 1]; });
  }
};
