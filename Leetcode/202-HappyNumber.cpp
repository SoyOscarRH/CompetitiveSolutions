class Solution {
 public:
  auto isHappy(int n) -> bool {
    auto seen = unordered_set<int> {1};

    while (not seen.count(n)) {
      seen.insert(n);

      auto future = 0;
      for (auto digit = 0; n != 0; n /= 10) {
        digit = n % 10;
        future += digit * digit;
      }
      n = future;
    }

    return n == 1;
  }
};