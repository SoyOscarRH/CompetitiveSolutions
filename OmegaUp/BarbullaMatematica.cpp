#include <iostream>
#include <string>
using namespace std;

using num = unsigned long long;

auto gauss(const num n) -> num { return (n * (n + 1)) / 2; }

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto total = num {};

  for (auto i = 1; i <= n; ++i) total += gauss(i);
  cout << total << endl;

  return 0;
}