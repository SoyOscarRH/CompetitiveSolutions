#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

auto get_neighbors(const vector<vector<char>>& keyboard) -> array<vector<char>, 256> {
  auto neighbors_of = array<vector<char>, 256> {};
  auto moves = vector<vector<int>> {{0, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0},
                                    {1, 1}, {0, 1},   {-1, 1}, {-1, 0}};

  for (auto letter = 'a'; letter <= 'z'; ++letter) {
    auto neighbors = vector<char> {};
    const auto y = (letter - 'a') / 9;
    const auto x = (letter - 'a') % 9;

    for (auto& move : moves) {
      auto dx = x + move[0], dy = y + move[1];

      if (dy < keyboard.size() and dy >= 0) {
        if (dx < keyboard[dy].size() and dx >= 0) {
          auto neighbor = keyboard[dy][dx];
          neighbors.push_back(neighbor);
        }
      }
    }
    /*
    cout << "n of " << letter << ": "
           << "x=" << x << " y=" << y << ": ";

    for (auto x : neighbors) { cout << x << "|"; }
    cout << endl;
    */

    neighbors_of[letter] = move(neighbors);
  }

  return neighbors_of;
}

auto solve(const array<vector<char>, 256>& neighbors_of) -> int {
  string word1, word2;
  cin >> word1 >> word2;

  if (word1 == word2) return 1;
  if (word1.size() != word2.size()) return 3;

  for (auto i = 0; i < word1.size(); ++i) {
    auto letter = word1[i];
    auto& neighbors = neighbors_of[word2[i]];

    if (find(begin(neighbors), end(neighbors), letter) == end(neighbors)) return 3;
  }

  return 2;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto keyboard = vector<vector<char>> {
      {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
      {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
      {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
  };

  auto neighbors_of = get_neighbors(keyboard);
  int test_cases;
  cin >> test_cases;
  for (auto test = 0; test < test_cases; ++test) cout << solve(neighbors_of) << '\n';

  return 0;
}