#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename number = int, typename index = int>
auto solution(const std::string numbers) -> number {
  auto validSubstrings = number {};
  for (auto digit : numbers) {
    if (digit == '4' || digit == '8' || digit == '0') ++validSubstrings;
  }

  auto lastPairIndex = index {static_cast<index>(numbers.size() - 1)};
  for (index i {}; i < lastPairIndex; ++i) {
    auto last2Digits = (numbers[i] - '0') * 10 + (numbers[i + 1] - '0');
    auto validSubstringsSinceHere = i + 1;
    if (last2Digits % 4 == 0)
      validSubstrings = validSubstrings + validSubstringsSinceHere;
  }

  return validSubstrings;
}

auto main() -> int {
  using namespace std;

  string numbers;
  cin >> numbers;

  cout << solution<unsigned long long, unsigned long long>(numbers) << endl;
  return 0;
}