struct Solution {
  const int one_buy = 0, one_buy_one_sell = 1, two_buys_one_sell = 2, two_buys_two_sells = 3;
  auto maxProfit(const vector<int>& prices) -> int {
    auto current = 0, next = 1;

    auto profit = array<array<int, 4>, 2> {};
    profit[current][one_buy] = profit[current][two_buys_one_sell] = INT_MIN;
    profit[current][one_buy_one_sell] = profit[current][two_buys_two_sells] = 0;

    for (const auto price : prices) {
      profit[next][one_buy] = max(profit[current][one_buy], 0 - price);
      profit[next][one_buy_one_sell] = max(profit[current][one_buy_one_sell], profit[current][one_buy] + price);
      profit[next][two_buys_one_sell] = max(profit[current][two_buys_one_sell], profit[current][one_buy_one_sell] - price);
      profit[next][two_buys_two_sells] = max(profit[current][two_buys_two_sells], profit[current][two_buys_one_sell] + price);
      swap(next, current);
    }

    return max(profit[current][one_buy_one_sell], profit[current][two_buys_two_sells]);
  }
};