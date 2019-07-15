#include <algorithm>
#include <array>
#include <map>
#include <string>
#include <vector>

class Solution {
 public:
  using array = std::array<int, 'z' - 'a' + 1>;

  auto getFormattedOutput(array result) {
    auto formatedResult = std::vector<std::string> {};
    auto currentLetter = 'a';
    for (auto seen : result) {
      if (seen) {
        formatedResult.reserve(formatedResult.size() + seen);
        while (seen--) formatedResult.push_back({currentLetter});
      }

      ++currentLetter;
    }

    return formatedResult;
  };

  auto commonChars(std::vector<std::string>& words) {
    array numTimesSeen {}, result {};
    result.fill(std::numeric_limits<int>::max());

    for (const auto& word : words) {
      for (const auto letter : word) ++numTimesSeen[letter - 'a'];

      for (auto i = int {}; i < numTimesSeen.size(); ++i) {
        result[i] = std::min(result[i], numTimesSeen[i]);
        numTimesSeen[i] = 0;
      }
    }

    return getFormattedOutput(result);
  }
};