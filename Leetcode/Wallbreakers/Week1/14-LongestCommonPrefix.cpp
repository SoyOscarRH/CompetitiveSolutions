class Solution {
 public:
  auto longestCommonPrefix(const vector<string>& words) -> string {
    auto prefix = string {};

    if (not words.size()) return prefix;

    for (auto index = 0; true; index++) {
      if (words[0].size() == index) return prefix;
      const auto letter_to_add = words[0][index];

      const auto all =
          std::all_of(begin(words), end(words), [=](const auto& word) {
            return word.size() != index and word[index] == letter_to_add;
          });

      if (not all) return prefix;

      prefix += letter_to_add;
    }

    return prefix;
  }
};