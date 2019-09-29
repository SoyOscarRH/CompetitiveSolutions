#include <iostream>
using namespace std;

int main() {
  auto test = 0;
  cin >> test;

  while (test--) {
    auto m = 0, n = 0;
    cin >> n >> m;

    auto g1 = (n - 1) % 4, g2 = (m - 1) % 3;
    auto grundy = g1 xor g2;

    cout << (grundy ? "Tuzik" : "Vanya") << '\n';
  }

  return 0;
}
