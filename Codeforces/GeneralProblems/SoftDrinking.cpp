#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int {
  int num_friends, num_bottles, capacity, limes, slices, salt, drink, salt_per_drink;
  cin >> num_friends >> num_bottles >> capacity >> limes >> slices >> salt;
  cin >> drink >> salt_per_drink;

  const auto alcohol_for_drinks = (num_bottles * capacity) / drink;
  const auto salt_for_drinks = salt / salt_per_drink;
  const auto limes_for_drinks = limes * slices;

  const auto num_shots = min({alcohol_for_drinks, salt_for_drinks, limes_for_drinks});

  cout << (num_shots / num_friends) << endl;

  return 0;
}