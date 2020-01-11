#include <iostream>
#include <numeric>

using namespace std;
using num = uint_fast64_t;

auto lcm(num a, num b) { return a * b / gcd(a, b); }
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto n = num {}, k = num {};
  cin >> n >> k;

  auto lcm_total = num {1}, buffer = num {};
  while (n-- and lcm_total) {
    cin >> buffer;
    lcm_total = lcm(lcm_total, buffer) % k;
  }

  cout << (lcm_total ? "No" : "Yes") << endl;

  return 0;
}