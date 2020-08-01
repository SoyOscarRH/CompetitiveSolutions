struct Solution {
  auto climbStairs(const int n) -> int {
    // base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    auto one_step_before = 2;
    auto two_steps_before = 1;
    auto all_ways = 0;

    for (auto i = 2; i < n; ++i) {
      all_ways = one_step_before + two_steps_before;
      two_steps_before = one_step_before;
      one_step_before = all_ways;
    }
    return all_ways;
  }
};