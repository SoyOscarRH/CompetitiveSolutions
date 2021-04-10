#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

auto solve(const string& line) -> string {
  auto elements = list<char> {};
  auto it = elements.begin();

  for (const auto c : line) {
    if (c == '[') { it = begin(elements); }
    else if (c == ']') { it = end(elements); }
    else { it = ++elements.insert(it, c); }
  }

  auto result = string {};
  for (const auto c : elements) { result += c; }

  return result;
}

auto main() -> int {
  string line;
  while (getline(cin, line)) { cout << solve(line) << endl; }

  return 0;
}