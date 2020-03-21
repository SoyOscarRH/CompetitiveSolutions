#include <iostream>
#include <string>
#include <cmath>
using namespace std;

using num = uint64_t;

auto area_cake(const num a) -> num {
  return 2 * a;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  num n;
  cin >> n;

  for (num i = 0, buffer = 0; i < n; ++i) {
    cin >> buffer;
    cout << "Area a comprar: " << area_cake(buffer) << "\n";
  }

  return 0;
}