class Solution {
 public:
  auto canConstruct(const string& ransom_note, const string& magazine) -> bool {
    auto letter_left = array<int, 128> {};
    letter_left.fill(-1);

    for (const auto letter : magazine) ++letter_left[letter];
    for (const auto letter : ransom_note) {
      if (letter_left[letter] < 0) return false;
      --letter_left[letter];
    }

    return true;
  }
};