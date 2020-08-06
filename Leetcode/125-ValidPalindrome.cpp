class Solution {
  inline auto next_valid(const string& s, int i) -> int {
    while (i < s.size() and not isalnum(s[i])) ++i;
    return i;
  }
  inline auto prev_valid(const string& s, int i) -> int {
    while (i >= 0 and not isalnum(s[i])) --i;
    return i;
  }

 public:
  auto isPalindrome(const string& s) -> bool {
    int l = 0, r = s.size() - 1;

    while (l < r) {
      l = next_valid(s, l + 1), r = prev_valid(s, r - 1);
      if (tolower(s[l]) != tolower(s[r])) return false;
    }

    return true;
  }
};