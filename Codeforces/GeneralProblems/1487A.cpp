#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const auto endline = '\n';

auto solve() -> int {
  int num_players;
  cin >> num_players;
  auto players = vector<int>(num_players);
  for (auto& player : players) { cin >> player; }

  const auto min = *min_element(begin(players), end(players));
  const auto losers = static_cast<int>(count(begin(players), end(players), min));

  return num_players - losers;
}

int main() {
  ios::sync_with_stdio(false);

  int test_cases;
  cin >> test_cases;
  while (test_cases--) { cout << solve() << endline; }

  return 0;
}