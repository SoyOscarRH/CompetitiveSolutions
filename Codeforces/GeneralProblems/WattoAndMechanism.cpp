#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template <typename number, number base = 29, number mod = 10000000009,
          char minCoefficient = 'a' - 1>
struct myHash {
  static inline auto encode(std::string& word) -> number {
    auto currentExp = number {1};
    auto result = number {};

    for (auto letter : word) {
      result += ((letter - minCoefficient) * currentExp) % mod;
      currentExp = (currentExp * base) % mod;  // need to move this
    }

    return result;
  }

  static inline auto getCoefficient(char letter, number currentCoefficient) -> number {
    return ((letter - minCoefficient) * currentCoefficient) % mod;
  }

  static inline auto getNextBase(number currentBase = 1) -> number {
    return (currentBase * base) % mod;
  }
};

using number = unsigned long long;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int initialStrings, queries;
  cin >> initialStrings >> queries;

  auto seen = unordered_set<number> {};
  auto sizes = unordered_set<size_t> {};

  // Read and store the initial strings
  auto word = string {};
  auto current = initialStrings;
  while (current--) {
    cin >> word;
    sizes.insert(word.size());
    seen.insert(myHash<number>::encode(word));
  }

  // For each query
  auto query = queries;
  while (query--) {
    auto foundIt = false;
    cin >> word;

    if (sizes.count(word.size()) == 0) {
      cout << "NO" << endl;
      continue;
    }

    const auto originalHash = myHash<number>::encode(word);
    auto currentBase = number {1};

    // for letter
    for (auto letter : word) {
      const auto incompleteHash =
          originalHash - myHash<number>::getCoefficient(letter, currentBase);

      // for each possible change
      auto possibleChanges = 2;
      while (possibleChanges--) {
        letter = letter == 'c' ? 'a' : letter + 1;

        auto newStep = myHash<number>::getCoefficient(letter, currentBase);
        if (seen.count(incompleteHash + newStep)) {
          foundIt = true;
          break;
        }
      }

      if (foundIt) {
        cout << "YES" << endl;
        break;
      }

      currentBase = myHash<number>::getNextBase(currentBase);
    }

    if (not foundIt) {
      cout << "NO" << endl;
    }
  }

  return 0;
}