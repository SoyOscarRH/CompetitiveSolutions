#include <iostream>
#include <list>

using namespace std;

auto main() -> int {
  int num_groups, bus_capacity;
  cin >> num_groups >> bus_capacity;

  auto groups = list<int>(num_groups);
  for (auto& group : groups) { cin >> group; }

  auto num_buses = 1;
  auto bus_passengers = 0;
  while (not groups.empty()) {
    if (bus_passengers + groups.front() <= bus_capacity) {
      bus_passengers += groups.front();
      groups.pop_front();
    } else {
      bus_passengers = 0;
      ++num_buses;
    }
  }

  cout << num_buses << endl;

  return 0;
}