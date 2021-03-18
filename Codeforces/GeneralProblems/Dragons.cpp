#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct dragon_t {
  int strength, bonus;
};

auto main() -> int {
  int life, num_dragons;
  cin >> life >> num_dragons;

  auto dragons = vector<dragon_t>(num_dragons);
  for (auto& dragon : dragons) { cin >> dragon.strength >> dragon.bonus; }

  sort(begin(dragons), end(dragons),
       [](const dragon_t d1, const dragon_t d2) { return d1.strength < d2.strength; });

  const auto will_win_all =
      all_of(begin(dragons), end(dragons), [current_life = life](const dragon_t dragon) mutable {
        if (current_life <= dragon.strength) { return false; }
        current_life += dragon.bonus;
        return true;
      });

  cout << (will_win_all ? "YES" : "NO") << endl;
  return 0;
}
