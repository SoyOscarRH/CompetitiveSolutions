#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  int num_cities;
  cin >> num_cities;

  auto cities = vector<int>(num_cities);
  for (auto& city : cities) { cin >> city; }

  if (num_cities == 1) {
    cout << 1 << endl;
    return 0;
  }

  const auto smaller = min_element(begin(cities), end(cities));
  const auto times_smaller = count(begin(cities), end(cities), *smaller);

  if (times_smaller > 1) {
    cout << "Still Rozdil" << endl;
  } else {
    cout << distance(begin(cities), smaller) + 1 << endl;
  }

  return 0;
}