#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  auto num_elements = 0;
  cin >> num_elements;

  auto nums = vector<int>(num_elements);
  for (auto& x : nums) { cin >> x; }

  auto midpoint = (nums.size() - 1) / 2;
  auto mid_iterator = begin(nums) + midpoint;
  nth_element(begin(nums), mid_iterator, end(nums));

  cout << nums[midpoint] << endl;

  return 0;
}