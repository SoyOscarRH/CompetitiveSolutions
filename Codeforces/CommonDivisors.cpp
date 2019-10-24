#include <iostream>
#include <numeric>

using namespace std;

template <typename T>
T countDivisors(T number) {
  T exponent, count {1};

  for (exponent = 0; (number & 1) == 0; ++exponent) number = number >> 1;
  if (exponent) count *= (exponent + 1);

  for (T i = 3; i * i <= number; i += 2) {
    for (exponent = 0; (number % i) == 0; ++exponent) number /= i;
    if (exponent) count *= (exponent + 1);
  }

  if (number > 1) count *= (1 + 1);

  return count;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  cin.tie(nullptr);
  cout.tie(nullptr);

  auto solution = 1ull, buffer = 0ull;
  auto numbers = 0;
  cin >> numbers;
  cin >> solution;

  while (--numbers) {
    cin >> buffer;
    solution = std::gcd(solution, buffer);
  }

  cout << countDivisors(solution) << endl;

  return 0;
}