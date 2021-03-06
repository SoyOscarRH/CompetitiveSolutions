#include <iostream>
#include <vector>

using namespace std;
using num = uint64_t;
const auto endline = '\n';

auto get_divisors(const num number) -> vector<num> {
  auto divisors = vector<num> {};

  for (num i = 1; i * i <= number; i++) {
    if (number % i == 0) {
      if (number / i != i) {
        divisors.push_back(i);
      } else
        divisors.push_back(i);
    }
  }

  return divisors;
}

auto cut(const num a, const num b, const num to_cut) -> num {
  if ((to_cut % a) == 0) return 1;
  if ((to_cut % b) == 0) return 1;

  for (auto divisor : get_divisors(to_cut)) {
    const auto other = to_cut / divisor;
    if (divisor <= b and other <= a) return 2;
  }

  return 3;
}

int main() {
  ios::sync_with_stdio(false);

  num a, b, c;
  cin >> a >> b >> c;

  if (a < b) swap(a, b);

  const auto to_cut = a * b - c;
  cout << min(cut(a, b, to_cut), cut(a, b, c)) << endl;

  return 0;
}