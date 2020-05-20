struct StockSpanner {
  vector<int> prices, last_day_down;
  StockSpanner() : prices {}, last_day_down {} {}

  auto next(const int last_price) -> int {
    const int today = prices.size();
    prices.push_back(last_price);

    if (today == 0) {
      last_day_down.push_back(0);
      return 1;
    }
    const auto yesterday = today - 1;
    const auto down_today = prices[yesterday] > last_price;
    last_day_down.push_back(down_today ? today : last_day_down[yesterday]);

    auto day_to_check = today;
    while (day_to_check >= 0 and prices[day_to_check] <= last_price)
      day_to_check = last_day_down[day_to_check] - 1;

    return today - day_to_check;
  }
};