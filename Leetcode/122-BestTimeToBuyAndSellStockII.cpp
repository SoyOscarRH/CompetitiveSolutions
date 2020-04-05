class Solution {
 public:
  auto maxProfit(const vector<int>& prices) -> int {
    int time_to_buy = 0, profit = 0, n = prices.size();
    for (int i = 1; i < n + 1; ++i) {
      const auto current = i == n ? 0 : prices[i];
      if (prices[i - 1] > current) {
        profit += prices[i - 1] - prices[time_to_buy];
        time_to_buy = i;
      }
    }

    return profit;
  }
};