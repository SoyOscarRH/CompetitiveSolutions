#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <array>

using namespace std;
using num = long double;

constexpr auto endline = '\n';

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  num N, M;
  cin >> N >> M;

  auto posts = array<num, 200> {}, old = array<num, 200> {};
  auto probability = array<array<num, 200>, 200> {};
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) { cin >> probability[i][j]; }
  }

  posts[0] = 1.0;
  for (auto step = 0; step < M; ++step) {
    swap(old, posts);
    fill(begin(posts), end(posts), 0);
    for (auto i = 0; i < N; ++i) {
      for (auto j = 0; j < N; ++j) { posts[j] += old[i] * probability[i][j]; }
    }
  }

  cout << fixed << setprecision(4);
  for (auto i = 0; i < N; ++i) { cout << posts[i] << endline; }

  return 0;
}
