#include <set>
#include <string>

int solve(std::string A) {
  const auto modulo = 10003;

  auto possibleSubstrings = A.length();
  auto valid =
      std::set<char> {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  auto solution = 0;
  for (auto letter : A) {
    if (valid.count(letter))
      solution = (solution + possibleSubstrings) % modulo;

    --possibleSubstrings;
  }

  return solution;
}