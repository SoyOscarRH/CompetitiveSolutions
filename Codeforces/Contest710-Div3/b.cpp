#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto solve(string& data, const int k, const int n) -> int {
  if (count(begin(data), end(data), '*') < 2) { return count(begin(data), end(data), '*'); }

  auto first = 0;
  for (auto i = 0; i < n; ++i) {
    if (data[i] == '*') {
      first = i;
      break;
    }
  }

  auto last = 0;
  for (auto i = n; i >= 0; --i) {
    if (data[i] == '*') {
      last = i;
      break;
    }
  }

  auto changes = 0;
  auto indexes = vector<int> {};
  for (auto i = first; i <= last; ++i) {
    if (data[i] == '*') { indexes.push_back(i); }
  }
  indexes.push_back(n + k + 10);

  int past = -(k + 10);
  for (auto i = 0; i < (indexes.size() - 1); ++i) {
    const auto current = indexes[i];
    const auto future = indexes[i + 1];

    if ((future - past) > k) {
      data[current] = 'x';
      past = current;
      changes++;
    }
  }

  return changes;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    int n, k;
    string data;
    cin >> n >> k >> data;
    cout << solve(data, k, n) << endl;
  }

  return 0;
}