class Solution {
 public:
  inline auto even(int num) { return num & 1 == 1; }

  auto sortArrayByParity(const vector<int>& nums) -> vector<int> {
    auto size = int {nums.size()};
    auto result = vector<int>(size, 0);
    auto start = 0, end = size - 1;

    for (const auto num : nums) {
      if (even(num))
        result[end--] = num;
      else
        result[start++] = num;
    }

    return result;
  }
};