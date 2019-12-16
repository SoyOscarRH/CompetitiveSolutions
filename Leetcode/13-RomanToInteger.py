class Solution:
    def __init__(self):
        self.symbols_value = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

    def romanToInt(self, roman_number: str) -> int:
        result = 0
        last_value = self.symbols_value[roman_number[0]]

        for symbol in roman_number:
            value = self.symbols_value[symbol]
            if (last_value < value):
                result -= last_value << 1

            result += value
            last_value = value

        return result
