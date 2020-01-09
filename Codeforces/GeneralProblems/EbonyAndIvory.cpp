#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

auto is_possible(int a, int b, int c) {
  for (int i = 0; i <= c; i += a) {
    if ((c - i) % b == 0) return true;
  }

  return false;
}

auto main() -> int {
  int a, b, c;
  cin >> a >> b >> c;

  if (is_possible(a, b, c))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
