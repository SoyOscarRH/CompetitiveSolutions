struct Solution {
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

struct Solution {
  auto plusOne(vector<int> digits) -> vector<int> {
    if (all_of(begin(digits), end(digits), [](const auto x) { return x == 9; })) {
      fill(begin(digits), end(digits), 0);
      digits.push_back(0);
      digits[0] = 1;

      return digits;
    }

    digits.back() += 1;

    auto i = rbegin(digits);
    while (*i == 10) {
      *i = 0;
      ++i;
      *i += 1;
    }

    return digits;
  }
};