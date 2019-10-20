#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  uint64_t rollo, quitar;
  cin >> rollo >> quitar;

  auto back_ups = 0ull;
  auto left_over = rollo % quitar;

  while (left_over) {
    ++back_ups;
    quitar = quitar - left_over;
    left_over = rollo % quitar;
  }

  cout << back_ups + 1 << endl;

  return 0;
}