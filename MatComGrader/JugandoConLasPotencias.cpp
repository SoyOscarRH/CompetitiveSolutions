#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

auto get_winner(array<int, 6>& moves) -> bool {
  auto num_piles = 0;
  cin >> num_piles;

  auto piles = vector<int>(num_piles);
  for (auto& pile : piles) cin >> pile;
  auto max_pile = *max_element(begin(piles), end(piles));

  array<int, 7> seen {};

  auto states = vector<int>(max_pile + 1);
  states[0] = 0;
  for (int current = 1; current <= max_pile; ++current) {
    for (auto move : moves) {
      auto action = current - move;
      if (action < 0) continue;

      auto grundy = states[action];
      seen[grundy] = current;
    }

    auto my_grundy = 0;
    while (my_grundy < seen.size() and seen[my_grundy] == current) ++my_grundy;

    states[current] = my_grundy;
  }

  auto result = 0;
  for (auto pile : piles) result ^= states[pile];

  return result != 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  array<int, 6> moves {1, 4, 27, 256, 3125, 46656};

  auto s1 = string {"Gana el primer jugador."},
       s2 = string {"Gana el segundo jugador."};

  auto tests = 0;
  cin >> tests;
  while (tests--) {
    cout << (get_winner(moves) ? s1 : s2) << '\n';
  }

  return 0;
}