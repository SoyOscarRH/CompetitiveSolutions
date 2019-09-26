#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int words_a, words_b;
  cin >> words_a >> words_b;

  auto seen = unordered_set<string> {};

  auto data = string {};
  for (int i = 0; i < words_a; i++) {
    cin >> data;
    seen.insert(data);
  }

  auto common = 0;
  for (int i = 0; i < words_b; i++) {
    cin >> data;
    if (seen.count(data)) ++common;
  }

  if (common % 2 == 1) ++words_a;

  if (words_a > words_b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}