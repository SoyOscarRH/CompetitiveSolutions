#include <array>
#include <utility>

template <typename T, size_t row, size_t col>
using matrix = std::array<std::array<T, col>, row>;

class Solution {
  using number = int;
  const number prime = 1e9 + 7;
  const number not_found = -1;

  matrix<number, 31, 1001> memory;

 public:
  Solution() {
    for (auto& target : memory) target.fill(not_found);
  }

  int numRollsToTarget(int d, int f, int target) {
    if (target <= 0 or d == 0) return target == d;
    if (memory[d][target] != not_found) return memory[d][target];

    auto ways = number {};
    for (number r = 1, newTarget = target; r <= f and r <= target; ++r) {
      ways = (ways + numRollsToTarget(d - 1, f, --newTarget)) % prime;
    }

    memory[d][target] = ways;

    return ways;
  }
};
