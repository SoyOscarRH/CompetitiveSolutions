struct Solution {
  unordered_map<char, int> symbols_value {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                          {'C', 100}, {'D', 500}, {'M', 1000}};

  auto romanToInt(const string& roman_number) -> int {
    auto result = 0;
    auto last_value = symbols_value[roman_number[0]];

    for (const auto symbol : roman_number) {
      const auto value = symbols_value[symbol];
      if (last_value < value) result -= last_value << 1;

      result += value;
      last_value = value;
    }

    return result;
  }
};