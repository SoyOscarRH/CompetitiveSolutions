struct Solution {
  auto get_bit(const int number, const int i) -> int { return (number >> i) bitand 1; }

  auto addBinary(const string& a, const string& b) -> string {
    auto const n = max(a.size(), b.size());
    auto sum = a.size() < b.size() ? b : a;
    auto carry = 0;

    for (int i = a.size() - 1, j = b.size() - 1, k = n - 1; i >= 0 or j >= 0; --i, --j, --k) {
      const auto a_i = i >= 0 ? a[i] - '0' : 0, b_i = j >= 0 ? b[j] - '0' : 0;
      sum[k] = a_i + b_i + carry;
      carry = get_bit(sum[k], 1);
      sum[k] = get_bit(sum[k], 0);
      sum[k] += '0';
    }

    if (carry) return "1" + sum;
    return sum;
  }
};