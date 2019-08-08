#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

auto maxSubsetSum(const vector<int> data) -> int {
  // We start at index = 2
  auto takeOneBeforeLast = data[0], takeLast = max(data[0], data[1]);

  for (auto i = 2; i < data.size(); ++i) {
    const auto current = data[i], temporal = takeLast;
    takeLast = max({current, takeLast, takeOneBeforeLast + current});
    takeOneBeforeLast = temporal;
  }

  return takeLast;
}

int main() {
  auto x = vector<int> {3, 7, 4, 6, 5};
  cout << maxSubsetSum(x) << endl;

  return 0;
}
