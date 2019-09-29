#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto get_winner() -> bool {
  auto num_piles = 0, num_of_moves = 0;
  cin >> num_piles >> num_of_moves;

  auto moves = vector<int>(num_of_moves);
  for (auto& move : moves) cin >> move;

  auto piles = vector<int>(num_piles);
  for (auto& pile : piles) cin >> pile;
  auto max_pile = *max_element(begin(piles), end(piles));

  auto seen = vector<int>(num_of_moves);

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

  auto s1 = string {"Gana el primer jugador."},
       s2 = string {"Gana el segundo jugador."};

  auto tests = 0;
  cin >> tests;

  while (tests--) {
    cout << (get_winner() ? s1 : s2) << '\n';
  }

  return 0;
}