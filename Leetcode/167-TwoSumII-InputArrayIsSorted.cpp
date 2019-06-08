#include <iostream>
#include <map>
#include <vector>

using namespace std;
auto twoSum(const vector<int> numbers, int target) -> vector<int> {
  int i, j {};
  for (auto it {numbers.begin()}, end {numbers.end()}; it != end; ++it) {
    const auto toFind = target - *it;
    const auto result = lower_bound(it + 1, end, toFind);

    if (result != end and *result == toFind) {
      const int i {it - numbers.begin()};
      const int j {result - numbers.begin()};
      return {i + 1, j + 1};
    }
  }

  return {0, 0};
}
