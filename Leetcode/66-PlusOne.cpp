class Solution {
 public:
  auto plusOne(vector<int> digits) -> vector<int> {
    const auto n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
      digits[i] += 1;
      digits[i] %= 10;

      if (digits[i]) return digits;
    }

    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};