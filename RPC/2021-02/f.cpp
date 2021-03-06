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
    --values[i].value;
  }

  auto person_to_choose = 0;
  for (int n = values.size(); n != 1; --n) {
    const auto times = values[person_to_choose].value;
    const auto chosen = (person_to_choose + times) % n;
    values.erase(begin(values) + chosen);
    person_to_choose = chosen % (n - 1);
  }

  cout << values[0].original_id << endl;

  return 0;
}