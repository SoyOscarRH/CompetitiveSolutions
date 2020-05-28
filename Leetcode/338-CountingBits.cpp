struct Solution {
  auto countBits(const int max_number) -> vector<int> {
    auto num_ones_in = vector<int>(max_number + 1);
    for (auto num = 1; num <= max_number; ++num) {
      const auto num_without_last_bit = num / 2;
      const auto last_bit = num & 1;
      num_ones_in[num] = num_ones_in[num_without_last_bit] + last_bit;
    }

    return num_ones_in;
  }
};
