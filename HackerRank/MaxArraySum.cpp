#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

auto maxSubsetSum(const vector<int> data) -> int {
  // We start at index = 2
  auto bestUntilPenultimate = data[0];
  auto bestUntilLast = max(data[0], data[1]);

  for (auto i = size_t {2}; i < data.size(); ++i) {
    const auto bestOption =
        max({data[i], bestUntilLast, bestUntilPenultimate + data[i]});

    bestUntilPenultimate = bestUntilLast;
    bestUntilLast = bestOption;
  }

  return bestUntilLast;
}

int main() {
  auto x = vector<int> {3, 7, 4, 6, 5};
  cout << maxSubsetSum(x) << endl;

  return 0;
}
