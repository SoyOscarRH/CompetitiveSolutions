class Solution {
 public:
  auto fizzBuzz(int n) -> vector<string> {
    auto result = vector<string> {};

    for (int i = 1; i <= n; ++i) {
      auto current = string {};

      if (i % 3 == 0) current += "Fizz";
      if (i % 5 == 0) current += "Buzz";

      if (current == "") current = to_string(i);

      result.push_back(current);
    }

    return result;
  }
};