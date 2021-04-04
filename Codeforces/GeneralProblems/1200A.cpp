#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

enum class state { empty = 0, full = 1 };

auto main() -> int {
  int n = 0;
  cin >> n;

  auto events = vector<char>(n);
  for (auto& event : events) { cin >> event; }

  auto rooms = vector<state>(10, state::empty);
  for (auto event : events) {
    if (event == 'L') { *find(begin(rooms), end(rooms), state::empty) = state::full; }
    if (event == 'R') { *find(rbegin(rooms), rend(rooms), state::empty) = state::full; }
    if (isdigit(event)) { rooms.at(event - '0') = state::empty; }
  }

  for (auto room : rooms) { cout << static_cast<int>(room); }
  cout << endl;
  
  return 0;
}