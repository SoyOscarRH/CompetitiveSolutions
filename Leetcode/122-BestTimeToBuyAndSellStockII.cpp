struct Solution {
  auto maxProfit(const vector<int>& prices) -> int {
    int time_to_buy = 0, profit = 0, n = prices.size();

    for (int day = 1; day < n + 1; ++day) {
      const auto current = day == n ? 0 : prices[day];
      if (prices[day - 1] > current) {
        profit += prices[day - 1] - prices[time_to_buy];
        time_to_buy = day;
      }
    }

    return profit;
  }
};

