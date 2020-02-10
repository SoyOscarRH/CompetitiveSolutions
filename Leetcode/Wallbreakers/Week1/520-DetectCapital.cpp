class Solution {
 public:
  auto detectCapitalUse(const string& word) -> bool {
    if (word.size() < 2) return true;

    const auto capital = [](char x) { return 'A' <= x and x <= 'Z'; };
    if (not capital(word[0]) and capital(word[1])) return false;

    const auto second = capital(word[1]);

    return all_of(begin(word) + 1, end(word),
                  [=](auto x) { return capital(x) == second; });
  }
};