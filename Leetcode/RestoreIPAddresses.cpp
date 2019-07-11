#include <array>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  auto restoreIpAddresses(std::string s) {
    const auto valid_sizes = std::array<int, 3> {1, 2, 3};
    auto result = std::vector<std::string> {};

    for (const auto a : valid_sizes) {
      if (a > s.size()) continue;

      for (const auto b : valid_sizes) {
        if (a + b > s.size()) continue;

        for (const auto c : valid_sizes) {
          if (a + b + c > s.size()) continue;

          for (const auto d : valid_sizes) {
            if (a + b + c + d != s.size()) continue;

            int A = stoi(s.substr(0, a));
            int B = stoi(s.substr(a, b));
            int C = stoi(s.substr(a + b, c));
            int D = stoi(s.substr(a + b + c, d));

            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
              auto example = std::to_string(A) + "." + std::to_string(B) + "." +
                             std::to_string(C) + "." + std::to_string(D);

              if (example.length() == s.size() + 3)
                result.emplace_back(example);
            }
          }
        }
      }
    }

    return result;
  }
};