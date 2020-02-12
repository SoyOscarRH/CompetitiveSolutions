class Solution {
 public:
  string reverseWords(string s) {
    const auto limit = s.size();
    for (auto start = 0; start < limit;) {
      auto end = start;

      while (end < limit and s[end] != ' ') ++end;
      reverse(begin(s) + start, begin(s) + end);

      start = end + 1;
    }

    return s;
  }
};