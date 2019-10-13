#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto main() -> int {
  int_fast64_t bands;
  cin >> bands;

  auto bodies = vector<int_fast64_t>(bands);
  for (auto& i : bodies) cin >> i;

  auto you = bodies[0];
  bodies.erase(begin(bodies));
  auto& others = bodies;

  sort(begin(bodies), end(bodies));

  while (others.size() > 1) {
    auto times = others[0];
    auto num_others_bands = others.size();

    you -= num_others_bands * (times - 1);
    you -= (num_others_bands - 1);

    bodies.erase(begin(bodies));

    if (you < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  auto total = others[0];

  if (you >= total)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  return 0;
}