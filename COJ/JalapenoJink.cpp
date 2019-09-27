#include <iostream>
#include <vector>
using namespace std;

auto count_divisors(int number) -> int {
  auto divisors = 0, i = 1;
  for (; i * i < number; ++i) {
    if (number % i) continue;
    divisors += 2;
  }

  if (i * i == number) ++divisors;

  return divisors;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto tests = 0;
  cin >> tests;

  for (auto test = 1; test <= tests; ++test) {
    auto N = 0;
    cin >> N;

    auto result = N - count_divisors(N);
    if ((N & 1) == 1) result--;
 
    cout << "Case #" << test << ": " << max(result, 0) << '\n';
  }

  return 0;
}