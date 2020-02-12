class Solution {
 public:
  auto detectCapitalUse(const string& word) -> bool {
    const auto is_capital = [](char x) { return 'A' <= x and x <= 'Z'; };

    const auto num_capitals =
        count_if(begin(word), end(word),
                 [=](char letter) { return is_capital(letter); });

    if (word.size() == num_capitals) return true;
    if (num_capitals == 0) return true;
    if (num_capitals == 1 and is_capital(word[0])) return true;

    return false;
  }
};