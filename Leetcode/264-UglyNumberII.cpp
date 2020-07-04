struct Solution {
  auto nthUglyNumber(const int n) -> int {
    auto uglies = vector<int>(n);
    uglies[0] = 1;
    auto prime_2 = 0, prime_3 = 0, prime_5 = 0;

    for (auto i = 1; i < n; ++i) {
      const auto x_2 = uglies[prime_2] * 2, x_3 = uglies[prime_3] * 3, x_5 = uglies[prime_5] * 5;
      const auto next = min({x_2, x_3, x_5});
      if (next == x_2) ++prime_2;
      if (next == x_3) ++prime_3;
      if (next == x_5) ++prime_5;

      uglies[i] = next;
    }

    return uglies[n - 1];
  }
};