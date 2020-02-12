class Solution {
 public:
  auto is_self_dividing(const int nums) -> bool {
    auto digits = nums;

    for (auto digit = 0; digits; digits /= 10) {
      digit = digits % 10;
      if (digit == 0 or nums % digit) return false;
    }

    return true;
  }

  auto selfDividingNumbers(int left, int right) -> vector<int> {
    auto result = vector<int> {};
    auto current = left;

    while (current <= right) {
      if (is_self_dividing(current)) result.push_back(current);

      ++current;
    }

    return result;
  }
};