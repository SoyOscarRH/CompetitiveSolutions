#include <iostream>
#include <queue>
#include <string>

using namespace std;

auto main() -> int {
  string data;
  cin >> data;

  auto word = queue<char> {{'h', 'e', 'l', 'l', 'o'}};
  for (const auto letter : data) {
    if (letter == word.front()) { word.pop(); }
  }

  cout << (word.empty() ? "YES" : "NO") << endl;

  return 0;
}