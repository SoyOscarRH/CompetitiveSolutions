#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  auto total = 0ull;
  auto data = vector<uint64_t>(n);
  for (auto& i : data) {
    cin >> i;
    total += i;
  }

  uint64_t current = data[0] * data[0];
  total -= data[0];

  auto max_calculation = current * total;

  for (auto i = 1; i < data.size() - 1; ++i) {
    const auto element = data[i];
    current += element * element;
    total -= element;
    auto break_here = current * total;

    if (break_here > max_calculation) max_calculation = break_here;
  }

  cout << max_calculation << endl;

  return 0;
}