#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

auto main() -> int {
  int num_elements;
  cin >> num_elements;
  auto nums = vector<int>(num_elements);
  for (auto& num : nums) { cin >> num; }

  auto change_indexes = vector<int> {-1};
  for (auto i = 0; i < (nums.size() - 1); ++i) {
    if (nums[i] > nums[i + 1]) { change_indexes.push_back(i); }
  }
  change_indexes.push_back(num_elements - 1);

  auto distances = vector<int> {};
  for (auto i = 0; i < (change_indexes.size() - 1); ++i) {
    distances.push_back(change_indexes[i + 1] - change_indexes[i]);
  }

  cout << *max_element(begin(distances), end(distances)) << endl;

  return 0;
}