#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

inline auto valid(int x) -> bool { return x >= 0; };

int main() {
  auto pile = 1000005;

  auto K = 3;
  auto L = 4;
  cin >> K >> L;

  auto states = vector<char>(pile + 1);
  states[0] = 'p';

  for (int current = 1; current <= states.size(); ++current) {
    array<int, 3> options {current - 1, current - K, current - L};

    auto can_get_to_p = any_of(begin(options), end(options), [&](int option) {
      return valid(option) and states[option] == 'p';
    });

    states[current] = can_get_to_p ? 'n' : 'p';
  }

  auto test_cases = 0;
  cin >> test_cases;

  while (test_cases--) {
    auto size_n = 0;
    cin >> size_n;

    cout << (states[size_n] == 'n'? 'A' : 'B');
  }

  cout << endl;

  return 0;
}