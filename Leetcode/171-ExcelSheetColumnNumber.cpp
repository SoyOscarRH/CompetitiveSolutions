struct Solution {
  auto titleToNumber(const string& word) -> int {
    auto result = 0;
    for (const auto letter : word) {
      const int value = (letter - 'A') + 1;
      result *= 26;
      result += value;
    }

    return result;
  }
};