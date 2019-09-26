#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  auto pile = 20;

  auto valid = [](int x) { return x >= 0; };

  auto states = vector<char>(pile + 1);
  states[0] = 'p';

  for (int current = 1; current <= states.size(); ++current) {
    auto options = vector<int> {current - 1};

    auto can_get_to_p = any_of(begin(options), end(options), [&](int option) {
      return valid(option) and states[option] == 'p';
    });

    states[current] = can_get_to_p ? 'n' : 'p';
  }

  auto current = 0;
  for (auto state : states) {
    cout << current++ << ": " << state << endl;
  }

  return 0;
}