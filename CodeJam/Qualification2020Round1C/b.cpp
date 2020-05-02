#include <algorithm>
#include <iostream>

#include <array>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long long;

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";
  auto unused = 0ull;
  cin >> unused;

  auto data = array<num, 256> {};
  auto data_zero = array<bool, 256> {};

  auto buffer = string {};
  for (auto i = 0ull, aux = 0ull; i < 10000; ++i) {
    cin >> aux >> buffer;
    ++data[buffer[0]];
    for (auto x : buffer) data_zero[x] = true;
  }

  auto result = vector<pair<int, char>> {};
  for (auto i = 0; i < 256; ++i)
    if (data[i]) result.emplace_back(data[i], i);

  sort(begin(result), end(result));

  for (auto i = 0; i <    9; ++i) data_zero[result[i].second] = false;
  for (auto i = 0; i <  256; ++i) if (data_zero[i]) cout << char(i);
  for (auto i = 8; i >=   0; --i) cout << result[i].second;

  cout << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto test = 1; test <= tests; ++test) solve(test);

  return 0;
}