#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  auto search(const std::vector<int>& nums, const int target) -> int {
    auto start = nums.begin(), end = nums.end() - 1;

    while (start <= end) {
      const auto middle = start + (end - start) / 2;

      cout << "start " << *start << endl;
      cout << "end " << *end << endl;

      cin.ignore();

      if (*middle == target) return middle - nums.begin();

      if (target < *middle)
        end = middle - 1;
      else
        start = middle + 1;
    }

    return -1;
  }
};

int main() {
  auto s = Solution {};
  auto v = std::vector<int> {-1, 0, 3, 5, 9, 12};
  s.search(v, 2);

  return 0;
}