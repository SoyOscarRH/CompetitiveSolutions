#include <algorithm>
#include <iostream>
#include <vector>

auto main() -> int {
  using namespace std;

  auto numbers = vector<pair<int, int>> {
      {4, 5},
      {1, 2},
      {1, 3},
      {1, 6},
  };

  cout << "Before: "
       << "\n";

  for (const auto couple : numbers) {
    cout << couple.first << " " << couple.second << "\n";
  }

  sort(begin(numbers), end(numbers),
       [](const pair<int, int>& couple1, const pair<int, int>& couple2) {
         if (couple1.first != couple2.first)
           return couple1.first < couple2.first;
         else
           return couple1.second > couple2.second;
       });

  cout << "\n"
       << "After: "
       << "\n";

  for (const auto couple : numbers) {
    cout << couple.first << " " << couple.second << "\n";
  }

  return 0;
}