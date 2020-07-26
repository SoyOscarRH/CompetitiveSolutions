struct Solution {
  auto addDigits(int num) -> int {
    int digit_sum = 0;
    for (; num > 0; num /= 10) { digit_sum += num % 10; }

    return digit_sum > 9 ? addDigits(digit_sum) : digit_sum;
  }
};