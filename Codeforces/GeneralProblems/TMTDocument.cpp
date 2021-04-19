
#include <bits/stdc++.h>
using namespace std;

auto is_possible(const int n, string& input) -> bool {
  auto left = stack<char> {}, right = stack<char> {};

  if (input.front() == 'M' or input.back() == 'M') { return false; }

  for (const auto symbol : input) {
    if (symbol == 'T') { left.push(symbol); } 
    else if (not left.empty()) { left.pop(); }
    else { return false; }
  }

  reverse(begin(input), end(input));

  for (const auto symbol : input) {
    if (symbol == 'T') { right.push(symbol); } 
    else if (not right.empty()) { right.pop(); } 
    else { return false; }
  }

  return left.size() == n / 3 and right.size() == n / 3;
}

auto main() -> int {
  int tests, size_of_input;
  cin >> tests;

  while (tests--) {
    auto input = string {};
    cin >> size_of_input >> input;
    cout << (is_possible(size_of_input, input) ? "YES" : "NO") << "\n";
  }

  return 0;
}


