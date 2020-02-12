class Solution {
 public:
  auto isPalindrome(const string& s) -> bool {
    auto left = begin(s), right = end(s) - 1;

    for (; left < right; ++left, --right) {
      while (left < end(s) and not isalnum(*left)) ++left;
      while (right >= begin(s) and not isalnum(*right)) --right;

      if (left >= end(s) or right < begin(s)) return true;

      if (tolower(*left) != tolower(*right)) return false;
    }

    return true;
  }
};