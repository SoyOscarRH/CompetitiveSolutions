#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  auto num_squares = 0, num_coins = 0;
  while (cin >> num_coins >> num_squares) {
    auto solution = 0, temporal = 0;
    while (num_coins--) {
      cin >> temporal;
      solution = solution xor temporal;
    }

    cout << (solution ? "Vida" : "Andrea") << '\n';
  }

  return 0;
}
