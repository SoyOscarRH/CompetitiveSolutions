struct Solution {
  auto myPow(const double x, const int64_t n) -> double {
    if (n < 0) return 1 / myPow(x, -n);
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n % 2 == 0) return myPow(x * x, n / 2);
    return x * myPow(x * x, (n - 1) / 2);
  }
};