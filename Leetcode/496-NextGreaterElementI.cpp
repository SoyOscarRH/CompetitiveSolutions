#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(const vector<int>& nums1,
                                 const vector<int>& nums2) {

    unordered_map<int, int> indexInNums2 {};
    for (size_t i {}; i < nums2.size(); ++i) indexInNums2[nums2[i]] = i;

    vector<int> result(nums1.size());
    
    int i {};

    for (auto num : nums1) {
      auto candidate {nums2.begin() + indexInNums2[num]};
      while (candidate != end(nums2) and *candidate <= num) ++candidate;

      if (candidate == end(nums2)) result[i++] = -1;
      else result[i++] = *candidate;
    }

    return result;
  }
};

int main() {
  vector<int> v1 {4, 1, 2}, v2 {1, 2, 3, 4};
  Solution s;
  auto x = s.nextGreaterElement(v1, v2);

  cout << endl;
  for (auto y : x) cout << y << endl;
  return 0;
}