#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using element = pair<int, int>;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n_slots;
  cin >> n_slots;
  auto slots = vector<element>(n_slots);
  for (auto& slot : slots) {
    cin >> slot.first >> slot.second;
    slot.second *= -1;
  } 

  int n_coins;
  cin >> n_coins;
  auto coins = vector<element>(n_coins);
  for (auto& coin : coins) {
    cin >> coin.first >> coin.second;
    coin.second *= -1;
  }

  sort(begin(coins), end(coins));

  auto total = 0ull;
  auto current_slot = 0;
  for (auto& coin : coins) {
    while (coin > slots[current_slot]) ++current_slot;
    cout << current_slot << endl;
    total += current_slot + 1;
  }

  cout << total << endl;

  return 0;
}