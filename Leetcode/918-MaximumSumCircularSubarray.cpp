struct Solution {
  auto kadane(const vector<int>& nums) -> int {
    auto best = INT_MIN, current = 0;
    for (const auto num : nums) {
      current = max(current + num, num);
      best = max(best, current);
    }

    return best;
  }

  auto maxSubarraySumCircular(vector<int>& nums) -> int {
    const auto negative = [](const auto x) { return x < 0; };
    if (all_of(begin(nums), end(nums), negative))
      return *max_element(begin(nums), end(nums));

    const auto normal = kadane(nums);
    const auto sum_of_all = accumulate(begin(nums), end(nums), 0);

    for (auto& num : nums) num = -num;
    const auto sum_of_not_to_take = kadane(nums);
    const auto weird = sum_of_all + sum_of_not_to_take;

    cout << normal << endl << weird;

    return max(normal, weird);
  }
};

struct Solution {
  auto maxSubarraySumCircular(vector<int>& nums) -> int {
    auto best_positive = INT_MIN, current_positive = 0;
    auto best_negative = INT_MIN, current_negative = 0;
    auto max_element = INT_MIN, sum_of_all = 0;

    for (const auto num : nums) {
      max_element = max(max_element, num);

      current_positive = max(current_positive + num, num);
      best_positive = max(best_positive, current_positive);

      current_negative = max(current_negative - num, -num);
      best_negative = max(best_negative, current_negative);
      sum_of_all += num;
    }

    if (max_element < 0) return max_element;
    const auto normal = best_positive;
    const auto sum_of_not_to_take = best_negative;
    const auto weird = sum_of_all + sum_of_not_to_take;

    return max(normal, weird);
  }
};