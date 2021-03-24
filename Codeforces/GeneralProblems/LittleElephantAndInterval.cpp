#include <iostream>
using namespace std;

auto special_nums_until(int64_t n) -> int64_t {
  if (n < 10) return n;

  const auto limit = n % 10;
  auto count = (n / 10) + 9;

  while (n >= 10) { n /= 10; }
  return (n > limit) ? count - 1 : count;
}

auto main() -> int {
  int64_t a, b;
  cin >> a >> b;

  cout << special_nums_until(b) - special_nums_until(a - 1);
}
