class Solution {
 public:
  int findComplement(const int num) {
    auto sum = 1, pow = 1;

    while (sum < num) {
      pow *= 2;
      sum += pow;
    }

    return sum - num;
  }
};