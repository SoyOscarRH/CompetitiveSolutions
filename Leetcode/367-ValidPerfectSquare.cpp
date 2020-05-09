struct Solution {
  auto isPerfectSquare(const int num) -> bool {
    auto left = 1, right = num;

    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (mid * mid == num) return true;

      if (mid < num / mid) left = mid + 1;
      else  right = mid - 1;
    }

    return false;
  }
};