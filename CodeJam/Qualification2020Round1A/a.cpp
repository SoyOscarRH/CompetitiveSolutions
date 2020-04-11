#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto candidates = vector<string> {};

bool is_sub(const string& str, const string& pattern) {
  cout << str << endline;
  const int n = str.size();
  const int m = pattern.size();
  if (m == 0) return (n == 0);

  bool lookup[n + 1][m + 1];

  memset(lookup, false, sizeof(lookup));

  lookup[0][0] = true;

  for (int j = 1; j <= m; j++)
    if (pattern[j - 1] == '*') lookup[0][j] = lookup[0][j - 1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pattern[j - 1] == '*')
        lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
      else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
        lookup[i][j] = lookup[i - 1][j - 1];
      else
        lookup[i][j] = false;
    }
  }

  return lookup[n][m];
}

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  int num_words = 0;
  cin >> num_words;

  auto words = vector<string>(num_words);
  for (auto& word : words) cin >> word;

  for (const auto& candidate : candidates) {
    if (all_of(begin(words), end(words),
               [&](const string& word) { return is_sub(candidate, word); }))
      cout << candidate << endline;
  }

  cout << "*" << endline;
}

auto main() -> int {
  auto initial = string("A", 100);
  auto i = 0;

  while (true) {
    candidates.push_back(initial);
    if (i == 99 and initial[i] == 'Z') break;

    if (initial[i] == 'Z')
      ++i;
    else
      ++initial[i];
  }

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto tests = 10;
  cin >> tests;
  i = 0;

  while (tests--) solve(++i);

  return 0;
}