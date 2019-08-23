#include <iostream>
#include <set>
#include <string>

using namespace std;

auto get_broken_numbers() -> set<char> {
  auto broken = set<char> {};

  auto number_of_broken_numbers = 0;
  auto broken_button = '0';
  cin >> number_of_broken_numbers;

  while (number_of_broken_numbers--) {
    cin >> broken_button;
    broken.insert(broken_button);
  }

  return broken;
}

int main() {
  const auto broken = get_broken_numbers();
  auto channel_to_get = 0;
  cin >> channel_to_get;

  auto min_number_of_presses = 1001;

  for (auto current_channel = 0; current_channel < 1000; ++current_channel) {
    auto is_possible_to_get_there = true;
    const auto digits = to_string(current_channel);

    for (const auto digit : digits) {
      if (broken.count(digit)) is_possible_to_get_there = false;
    }

    if (not is_possible_to_get_there) continue;

    auto distance = abs(current_channel - channel_to_get);
    min_number_of_presses = min(min_number_of_presses, distance);
  }

  cout << min_number_of_presses << endl;
}