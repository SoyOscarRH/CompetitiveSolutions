#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

enum class last_seen { none, c, j };

auto fill(string& data, const int i, vector<string>& options, const last_seen l) {
  if (i == data.size()) {
    options.push_back(data);
    return;
  }

  if (data[i] != '?') {
    fill(data, i + 1, options, l);
    return;
  }

  if (l == last_seen::c) {
    data[i] = 'C';
    fill(data, i + 1, options, l);
    return;
  }

  if (l == last_seen::j) {
    data[i] = 'J';
    fill(data, i + 1, options, l);
    return;
  }

  auto option1 = data;
  auto option2 = data;
  option1[i] = 'C';
  option2[i] = 'J';

  fill(option1, i + 1, options, last_seen::c);
  fill(option2, i + 1, options, last_seen::j);
}

auto solve(const int test_case) -> void {
  int x, y;
  cin >> x >> y;

  string text;
  cin >> text;

  auto options = vector<string> {};
  fill(text, 0, options, last_seen::none);

  auto min_count = max(x, y) * (text.size() + 2);
  for (const auto& option : options) {
    auto count = 0;
    for (auto i = 0; (i + 1) < text.size(); ++i) {
      const auto l1 = option[i];
      const auto l2 = option[i + 1];

      if (l1 == 'C' and l2 == 'J') { count += x; }
      if (l1 == 'J' and l2 == 'C') { count += y; }
    }
    min_count = min<int>(min_count, count);
  }

  cout << "Case #" << test_case << ": " << min_count << endl;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tests;
  cin >> tests;
  for (auto test = 1; test <= tests; ++test) { solve(test); }

  return 0;
}