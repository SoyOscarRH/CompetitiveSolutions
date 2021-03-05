#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve(const string& data) -> void {
  int points_of[2] = {0, 0};
  int games_of[2] = {0, 0};
  bool start_round_left = true;
  int the_winner = -1;

  const auto left = 0;
  const auto righ = 1;

  const auto show_game_result = [&]() {
    if (the_winner != -1) {
      cout << games_of[left] << (the_winner == left ? " (winner)" : "");
      cout << " - ";
      cout << games_of[righ] << (the_winner == righ ? " (winner)" : "");
      cout << endline;
    } else {
      cout << games_of[left] << " (" << points_of[left] << (start_round_left ? "*" : "") << ")";
      cout << " - ";
      cout << games_of[righ] << " (" << points_of[righ] << (start_round_left ? "" : "*") << ")";
      cout << endline;
    }
  };

  const auto updateGame = [&]() {
    {
      const auto [loser, winner] = minmax(points_of[righ], points_of[left]);

      const auto option1 = winner >= 5 and ((winner - loser) >= 2);
      const auto option2 = winner >= 10;

      if (option1 or option2) {
        if (winner == points_of[righ]) {
          ++games_of[righ];
        } else {
          ++games_of[left];
        }

        points_of[righ] = 0;
        points_of[left] = 0;
      }
    }

    {
      const auto winner = max(games_of[righ], games_of[left]);
      if (winner == 2) {
        if (winner == games_of[righ]) {
          the_winner = righ;
        } else {
          the_winner = left;
        }
      }
    }
  };

  for (const auto symbol : data) {
    if (symbol == 'Q') {
      show_game_result();
    } else if (symbol == 'S') {
      if (start_round_left) {
        ++points_of[left];
        start_round_left = true;
      } else {
        ++points_of[righ];
        start_round_left = false;
      }
    } else if (symbol == 'R') {
      if (start_round_left) {
        ++points_of[righ];
        start_round_left = false;
      } else {
        ++points_of[left];
        start_round_left = true;
      }
    }

    updateGame();
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string data;
  cin >> data;

  solve(data);

  return 0;
}