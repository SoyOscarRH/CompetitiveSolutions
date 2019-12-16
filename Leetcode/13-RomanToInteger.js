const romanToInt = roman_number => {
  const symbols_value = [];
  symbols_value["I"] = 1;
  symbols_value["V"] = 5;
  symbols_value["X"] = 10;
  symbols_value["L"] = 50;
  symbols_value["C"] = 100;
  symbols_value["D"] = 500;
  symbols_value["M"] = 1000;

  let result = 0;
  let last_value = symbols_value[roman_number[0]];

  for (const num_symbol of roman_number) {
    const value = symbols_value[num_symbol];
    if (last_value < value) result -= last_value << 1;

    result += value;
    last_value = value;
  }

  return result;
};
