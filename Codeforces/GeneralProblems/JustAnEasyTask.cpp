#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

auto endLine = '\n';

using namespace std;

template <class T>
inline T gcd(T a, T b) {
  T r {}, i {};
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  uint64_t n;
  cin >> n;

  uint64_t numberOfTimesThatWeGenerateAll {};

  vector<uint64_t> numbers(n, 0);
  unordered_map<uint64_t, int> gcds {};
  numbers[0] += n;

  uint64_t numOfColumnsToCheck = n / 2;
  if (n % 2 == 0) numOfColumnsToCheck -= 1;

  for (uint64_t i {1}; i <= numOfColumnsToCheck; ++i) {
    uint64_t sizeOfRepit {gcd(i, n)};

    if (sizeOfRepit == 1)
      numberOfTimesThatWeGenerateAll += 2;
    else
      ++gcds[sizeOfRepit];
  }

  for (const auto& OneGCD : gcds) {
    uint64_t sizeOfRepit {OneGCD.first};

    uint64_t index {}, times {n / sizeOfRepit};
    uint64_t toSum = {2 * sizeOfRepit * OneGCD.second};

    for (uint64_t j {}; j < times; ++j) {
      numbers[index] += toSum;
      index += sizeOfRepit;
      if (index >= n) index = index % n;
    }
  }

  if (n % 2 == 0) {
    uint64_t toSum = n / 2;
    numbers[0] += toSum;
    numbers[toSum] += toSum;
  }

  for (const auto& num : numbers) {
    cout << num + numberOfTimesThatWeGenerateAll << endLine;
  }

  return 0;
}