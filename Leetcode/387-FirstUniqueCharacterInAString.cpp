class Solution {
 public:
  template <typename container, typename index = int>
  auto firstUniqChar(const container& values) -> index {
   auto seen = std::array<char, 256> {};

    for (auto value : values) {
      auto& timesSeen = seen[value];
      if (timesSeen < 2) ++timesSeen;
    }

    index result {};
    for (auto value : values) {
      if (1 == seen[value]) return result;
      result++;
    }

    return -1;
  }
};