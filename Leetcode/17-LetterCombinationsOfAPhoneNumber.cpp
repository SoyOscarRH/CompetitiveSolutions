class Solution {
  vector<string> letters {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

 public:
  auto letterCombinations(const string& digits) -> vector<string> {
    if (digits.empty()) return {};

    auto combinations = vector<string> {""};

    for (const auto digit : digits) {
      const auto& candidates = letters[digit - '0'];
      if (not candidates.size()) continue;

      auto new_combinations = vector<string> {};

      for (const auto candidate : candidates) {
        for (const auto& prev_combination : combinations)
          new_combinations.push_back(prev_combination + candidate);
      }

      combinations.swap(new_combinations);
    }

    return combinations;
  }
};
