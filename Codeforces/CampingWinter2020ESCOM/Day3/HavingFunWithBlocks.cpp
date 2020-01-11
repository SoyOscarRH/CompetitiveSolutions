#include <iostream>

using namespace std;
using num = uint64_t;

const num mod = 1000000007;
struct vec {
  num a, b, c, d;
};

vec operator*(const vec& x, const vec& y) {
  const auto a11 = (x.a * y.a) % mod + (x.b * y.c) % mod;
  const auto a12 = (x.a * y.b) % mod + (x.b * y.d) % mod;
  const auto a21 = (x.c * y.a) % mod + (x.d * y.c) % mod;
  const auto a22 = (x.c * y.b) % mod + (x.d * y.d) % mod;

  return {a11 % mod, a12 % mod, a21 % mod, a22 % mod};
}

auto bin_expo(const vec x, const num n) -> vec {
  if (n == 0) return vec {1, 0, 0, 1};
  if (n == 1) return x;

  if (n % 2 == 0) return bin_expo(x * x, n / 2);
  return x * bin_expo(x * x, (n - 1) / 2);
}

auto main() -> int {
  auto k = num {};
  cin >> k;

  auto const result = bin_expo({3, 8, 1, 3}, k - 1);
  auto value = result.c * 3 + result.d * 1;
  value %= mod;

  cout << (value * value) % mod << endl;

  return 0;
}