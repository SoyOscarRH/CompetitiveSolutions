#include <cstdint>
#include <iostream>
using namespace std;

using num = uint64_t;

inline auto remainder_with_4(num n) -> num { return n & 3; }

auto computeXOR(num n) -> num {
  switch (remainder_with_4(n)) {
    case 0: return n;             // if n is multiple of 4
    case 1: return 1;             // If n % 4 gives remainder 1
    case 2: return n + 1;         // If n % 4 gives remainder 2
    default: return 0;            // If n % 4 gives remainder 3
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  num grundy = 0;

  num quarries = 0;
  cin >> quarries;
  while (quarries--) {
    num stones_first = 0, num_dumpers = 0;
    cin >> stones_first >> num_dumpers;

    grundy ^=
        computeXOR(stones_first - 1) ^ computeXOR(stones_first + num_dumpers - 1);
  }

  cout << (grundy ? "tolik" : "bolik") << '\n';

  return 0;
}
