class Solution {
  static auto isCapital(const char x) -> bool { return 'A' <= x and x <= 'Z'; };

 public:
  auto detectCapitalUse(const string& word) -> bool {
    const auto num_capitals = count_if(begin(word), end(word), isCapital);

    if (word.size() == num_capitals) return true;
    if (num_capitals == 0) return true;
    if (num_capitals == 1 and isCapital(word[0])) return true;

    return false;
  }
};