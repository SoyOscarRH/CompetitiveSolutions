#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve(unordered_set<string>& data) -> void {
  auto word = string {};
  getline(cin, word);

  if (word == "") return;

  transform(begin(word), end(word), begin(word), [](char c) -> int {
    return tolower(c);
  });

  transform(begin(word), end(word), begin(word),
            [](char x) { return x == ' ' ? '-' : x; });

  data.insert(word);
}

auto main() -> int {
  ios::sync_with_stdio(false);

  auto data = unordered_set<string> {};
  auto words = 10;
  cin >> words;

  words += 1;

  while (words--) {
    solve(data);
  }

  cout << data.size() << endl;

  return 0;
}