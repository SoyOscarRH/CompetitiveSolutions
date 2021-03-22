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

  auto sorted = nums;
  sort(begin(sorted), end(sorted));

  auto times = 0;
  for (auto i = 0; i < num_elements; ++i) {
    if (nums[i] != sorted[i]) { ++times; }
    if (times > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}