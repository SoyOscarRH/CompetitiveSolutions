#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using num = uint64_t;

struct person {
  int original_id, value;
};

auto main() -> int {
  ios::sync_with_stdio(false);

  int num_people;
  cin >> num_people;
  auto values = vector<person>(num_people);
  for (auto i = 0; i < num_people; ++i) {
    cin >> values[i].value;
    values[i].original_id = i + 1;
  }

  while (values.size() != 1) {
    const auto times = values[0].value;
    const auto chosen = times % values.size();
    values.erase(begin(values) + chosen);
  }

  cout << values[0].original_id << endl;

  return 0;
}