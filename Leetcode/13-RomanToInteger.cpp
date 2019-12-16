class Solution {
 public:
  array<int, 256> symbols_value;

  Solution() {
    symbols_value['I'] = 1;
    symbols_value['V'] = 5;
    symbols_value['X'] = 10;
    symbols_value['L'] = 50;
    symbols_value['C'] = 100;
    symbols_value['D'] = 500;
    symbols_value['M'] = 1000;
  }

  int romanToInt(const string roman_number) {
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