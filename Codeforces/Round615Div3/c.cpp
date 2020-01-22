#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int_fast64_t;
const auto endline = '\n';

template <typename T>
std::vector<std::pair<T, T> > PrimeFactorization(T n) {
  std::vector<std::pair<T, T> > Factors;
  T exponent;

  for (exponent = 0; (n & 1) == 0; ++exponent) n = n >> 1;
  if (exponent) Factors.emplace_back(2, exponent);

  for (T i = 3; i * i <= n; i += 2) {
    for (exponent = 0; (n % i) == 0; ++exponent) n /= i;
    if (exponent) Factors.emplace_back(i, exponent);
    if (Factors.size() > 2) break;
  }

  if (n > 1) Factors.emplace_back(n, 1);

  return Factors;
}

auto solve() {
  num n = 0;
  cin >> n;

  const auto factors = PrimeFactorization(n);
  if (factors.size() == 1) {
    if (factors[0].second < 6) {
      cout << "NO" << endline;
      return;
    }

    const auto factor = factors[0].first;
    const auto one = factor;
    const auto two = factor * factor;
    const auto three = (n / one) / two;

    cout << "YES" << endline;
    cout << one << " " << two << " " << three << endline;
    return;
  }

  const auto one = factors[0].first;
  const auto two = factors[1].first;
  const auto three = (n / one) / two;

  if (three == 1 or one == three or two == three) {
    cout << "NO" << endline;
    return;
  }

  cout << "YES" << endline;
  cout << one << " " << two << " " << three << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  auto tests = 0;
  cin >> tests;

  while (tests--) solve();

  return 0;
}
