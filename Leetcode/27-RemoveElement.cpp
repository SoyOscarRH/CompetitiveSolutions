#include <iostream>
#include <vector>

using namespace std;

auto removeElement(vector<int>& nums, const int val) -> int {
    int occurrences {}, validUntil {};
    
    for (int number : nums) {
        if (number == val) ++occurrences;
        else nums[validUntil++] = number;
    }
    
    return nums.size() - occurrences;
}