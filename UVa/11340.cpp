#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

auto solve() -> string {
  int pairs;
  cin >> pairs;
  auto prices = map<char, int> {};
  for (auto i = 0; i < pairs; ++i) {
    int price;
    char c;
    cin >> c >> price;
    prices[c] = price;
  }

  int lines;
  cin >> lines;

  string buffer;
  getline(cin, buffer);

  auto article = vector<string>(lines);
  for (auto& line : article) { getline(cin, line); }

  auto money = 0;
  for (const auto& line : article) {
    for (const auto c : line) {
        money += prices[c];
    }
  }

  const auto dollars = money / 100;
  const auto cents = money % 100;

  return to_string(dollars) + "." + (cents < 10 ? "0" : "") + to_string(cents) + "$";
}

auto main() -> int {
  int num_test;
  cin >> num_test;
  while (num_test--) { cout << solve() << endl; }

  return 0;
}