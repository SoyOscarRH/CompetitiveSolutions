#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

auto is_possible_to_click(const string& channel, const set<char>& buttons) -> bool {
  const auto is_here = [&](const char button) { return buttons.count(button) != 0; };
  return none_of(begin(channel), end(channel), is_here);
}

int main() {
  int num_buttons;
  cin >> num_buttons;

  auto buttons = set<char> {};
  for (auto i = 0; i < num_buttons; ++i) {
    char button;
    cin >> button;
    buttons.insert(button);
  }

  int channel_to_get;
  cin >> channel_to_get;

  auto min_pushes = numeric_limits<int>::max();
  for (auto channel = 0; channel < 1000; ++channel) {
    if (is_possible_to_click(to_string(channel), buttons)) {
      min_pushes = min(min_pushes, abs(channel - channel_to_get));
    }
  }

  cout << min_pushes << endl;

  return 0;
}