struct Solution {
  auto fizzBuzz(const int n) -> vector<string> {
    auto results = vector<string> {};

    for (auto i = 1; i <= n; ++i) {
      auto current = string {};

      if (i % 3 == 0) current += "Fizz";
      if (i % 5 == 0) current += "Buzz";

      results.push_back(current == "" ? to_string(i) : current);
    }

    return results;
  }
};