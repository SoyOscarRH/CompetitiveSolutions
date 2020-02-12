class Solution {
 public:
  auto titleToNumber(const string& word) -> int {
    const int n = word.size();

    auto result = 0;
    for (const auto letter : word) {
      const int value = letter - 'A' + 1;
      result *= 26;
      result += value;
    }

    return result;
  }
};