#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
  const auto n = 1000;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto i = 1; i <= n; ++i) {
    auto text = string {};
    if (i % 3 == 0) text += "Fizz";
    if (i % 5 == 0) text += "Buzz";

    cout << (text == "" ? to_string(i) : text) << "\n";
  }

  return 0;
}