class Solution {
 public:
  auto canJump(const vector<int>& nums) -> bool {
    const auto n = nums.size();
    auto can_i_get = vector<bool>(n, false);
    auto seen = unordered_set<int> {};

    can_i_get[0] = true;
    for (auto i = 0; i < n; ++i) {
      if (not can_i_get[i]) return false;
      if (i + 1 == n) return true;

      if (auto id = nums[i] + i; seen.find(id) == end(seen)) {
        for (auto j = 1; j <= nums[i]; ++j) can_i_get[j + i] = true;
        seen.insert(id);
      }
    }

    return true;
  }
};