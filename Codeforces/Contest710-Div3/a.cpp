#include <array>
#include <iostream>
#include <cstdint>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    int64_t n, m, element;
    cin >> n >> m >> element;

    element -= 1;

    const auto x = element % n;
    const auto y = element / n;

    const auto new_element = x * m + y;
    cout << new_element + 1 << endl;
  }

  return 0;
}