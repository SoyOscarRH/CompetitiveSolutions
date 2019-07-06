#include <algorithm>
#include <iostream>
#include <cmath> 
using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tests, bolitas;
  cin >> tests;

  while (tests--) {
    cin >> bolitas;
    if ((bolitas % 2) == 0) {
      int r = log2(bolitas & -bolitas);
      if (r & 1)
        cout << "TAK" << "\n";
      else
        cout << "NIE" << "\n";

    } else
      cout << "NIE" << "\n";
  }

  return 0;
}
