class Solution {
 public:
  auto checkValidString(const string& s) -> bool {
    auto max_open_left = 0, min_open_left = 0;
    for (const auto letter : s) {
      min_open_left += letter == '(' ? +1 : -1;
      max_open_left += letter == ')' ? -1 : +1;

      if (max_open_left < 0) return false;
      min_open_left = max(0, min_open_left);
    }

    return min_open_left == 0;
  }
};