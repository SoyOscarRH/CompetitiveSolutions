class Solution {
 private:
  static constexpr auto INVALID = -1;

 public:
  auto firstBadVersion(const int n) -> int {
    if (isBadVersion(1)) return 1;
    auto good = 1, bad = n;

    while (good < bad) {
      if (good + 1 == bad) return bad;

      const auto possible = good + (bad - good) / 2;
      if (isBadVersion(possible))
        bad = possible;
      else
        good = possible;
    }

    return INVALID;
  }
};