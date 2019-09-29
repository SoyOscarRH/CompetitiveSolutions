#include <iostream>
using namespace std;

auto main() -> int {
  auto n = 0;
  cin >> n;

  if (n % 2) {
    cout << -1 << endl;
    return 0;
  }

  for (auto i = 1; i <= n; i += 2) {
    cout << i + 1 << " " << i << " ";
  }

  cout << endl;

  return 0;
}
