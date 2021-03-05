#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

const int LEFT = 0, RIGHT = 1;

struct goomba {
  num index;
  num direction;
  goomba* to_crash = nullptr;
};

auto print(const num L, const list<goomba>& gs) -> string {
  auto data = string(L, '_');
  for (const auto& g : gs) { data[g.index] = g.direction == LEFT ? '<' : '>'; }
  return data;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  num L, G;
  cin >> L >> G;
  const auto IMPOSSIBLE = L + 100;
  auto original_players = vector<goomba>(G);
  for (auto& g : original_players) { cin >> g.index >> g.direction; }

  sort(begin(original_players), end(original_players),
       [](const goomba& a, const goomba& b) { return a.index < b.index; });

  auto players = list<goomba>(begin(original_players), end(original_players));

  using point = list<goomba>::iterator;

  auto time_to_fall = [&](const point i) {
    const auto& g = *i;
    if (i == begin(players) and g.direction == LEFT) { return g.index; }
    if (next(i) == end(players) and g.direction == RIGHT) { return L - g.index; }

    return IMPOSSIBLE;
  };

  auto time_to_crash = [&](const point i) {
    auto& g = *i;

    if (g.direction == LEFT) {
      if (i == begin(players)) { return IMPOSSIBLE; }
      auto& j = *prev(i);
      if (j.direction == g.direction) return IMPOSSIBLE;

      g.to_crash = &j;
      return abs(j.index - g.index) / 2;
    }

    if (g.direction == RIGHT) {
      if (next(i) == end(players)) { return IMPOSSIBLE; }
      auto& j = *next(i);
      if (j.direction == g.direction) return IMPOSSIBLE;

      g.to_crash = &j;
      return abs(j.index - g.index) / 2;
    }

    return IMPOSSIBLE;
  };

  auto time = num {};

  while (!players.empty()) {
    auto elapsed = IMPOSSIBLE;

    for (auto i = players.begin(); i != end(players); ++i) {
      elapsed = min({
          elapsed,
          time_to_fall(i),
          time_to_crash(i),
      });
    }

    time += elapsed;
    for (auto& g : players) { g.index += (g.direction == LEFT ? -elapsed : elapsed); }
    for (auto i = players.begin(); i != end(players); ++i) {
      if (time_to_fall(i) == 0) {
        players.erase(i);
      } else if (time_to_crash(i) == 0) {
        auto& g = *i;

        g.direction = 1 - g.direction;
        g.index += (g.direction == LEFT ? 1 : -1);

        if (g.to_crash != nullptr) {
          auto& j = *(g.to_crash);

          g.direction = 1 - g.direction;
          j.direction = 1 - j.direction;

          g.index += (g.direction == LEFT ? 1 : -1);
          j.index += (j.direction == LEFT ? 1 : -1);

          g.to_crash = nullptr;
          j.to_crash = nullptr;
        }
      }
    }
  }

  cout << time << endline;

  return 0;
}
