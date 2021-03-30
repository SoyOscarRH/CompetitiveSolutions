struct Solution {
  auto numDifferentIntegers(const string& word) -> int {
    auto data = word + 'a', buffer = string {};
    auto nums = set<string> {};
    for (const auto letter : data) {
      if (isdigit(letter)) { buffer += letter; }

      if (not isdigit(letter) and buffer != "") {
        const auto j = find_if(begin(buffer), end(buffer), [](const auto l) { return l != '0'; });
        nums.emplace(j, end(buffer));
        buffer.clear();
      }
    }

    return nums.size();
  }
};