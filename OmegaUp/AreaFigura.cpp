#include <iostream>
#include <string>
using namespace std;

using num = long long;

auto area(const num n) -> num {
  auto total = num {};

  for (auto init = (2 * n) - 1; init >= 1; init -= 2) total += init;

  return total * 2 - (2 * n - 1);
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << area(n) << endl;

  return 0;
}