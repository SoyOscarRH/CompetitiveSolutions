#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

using num = uint64_t;

auto main() -> int {
  ios::sync_with_stdio(false);

  num n, m, a, c, x0;
  cin >> n >> m >> a >> c >> x0;

  a %= m;
  c %= m;
  x0 %= m;

  auto numbers = vector<num> {x0};
  numbers.reserve(n);

  for (auto i = 1; i <= n; ++i) {
    const auto multiplication = (a * numbers[i - 1]) % m;
    numbers.push_back((multiplication + c) % m);
  }

  numbers.erase(begin(numbers));

  auto count = 0;
  for (const auto value : numbers) {
    int low = 0;
    int high = numbers.size() - 1;

    while (low <= high) {
      const auto mid = (low + high) / 2;

      if (numbers[mid] == value) {
        ++count;
        break;
      }
      if (numbers[mid] > value) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }

  cout << count << endl;

  return 0;
}