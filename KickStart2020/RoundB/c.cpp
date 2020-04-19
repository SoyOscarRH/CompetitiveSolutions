#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

constexpr auto mod = 1000000000;

struct point {
  int_fast64_t x = 0, y = 0;
  auto reset() {
    x %= mod;
    y %= mod;
  }
};

auto operator+(const point p1, const point p2) -> point {
  return {p1.x + p2.x, p1.y + p2.y};
}

auto is_closing(char x) { return x == ')'; }

auto get_matching(const string& data, int index) {
  auto open = 0;

  for (auto i = index; i < data.size(); i++) {
    if (data[i] == '(')
      ++open;
    else if (data[i] == ')') {
      --open;
      if (not open) return i;
    }
  }

  return -1;
}

auto do_work(const string& data, int start, int finish) -> point {
  auto p = point {};
  for (auto i = start; i < finish; ++i) {
    if (data[i] >= 'A' and data[i] <= 'Z') {
      if (data[i] == 'N') --p.x;
      if (data[i] == 'S') ++p.x;
      if (data[i] == 'W') --p.y;
      if (data[i] == 'E') ++p.y;

      if (p.x < 0) p.x = mod - 1;
      if (p.y < 0) p.y = mod - 1;
    } else {
      const auto times = data[i] - '0';
      const auto new_start = i + 2;
      const auto new_end = get_matching(data, i + 1);

      auto dp = do_work(data, new_start, new_end);
      dp.x *= times, dp.y *= times;
      dp.reset();
      p = dp + p;
      p.reset();
      i = new_end;
    }
  }
  p.reset();

  return p;
};

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  auto data = string {};
  cin >> data;

  auto p = do_work(data, 0, data.size());
  cout << p.y + 1 << " " << p.x + 1 << endline;
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