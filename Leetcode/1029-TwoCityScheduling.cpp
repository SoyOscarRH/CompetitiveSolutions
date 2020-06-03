struct Solution {
  auto twoCitySchedCost(const vector<vector<int>>& costs) -> int {
    const auto select_a = [](auto acc, const auto& cost) { return acc + cost[0]; };
    const auto price_if_all_to_a = accumulate(cbegin(costs), cend(costs), 0, select_a);

    // refund[i] is how much $ are we going to "get back" if we send i to city B.
    auto refunds = vector<int> {};
    for (const auto& cost : costs) refunds.push_back(cost[0] - cost[1]);

    // nth_element gets the bigger half elements at the beginning, so we can take
    const auto half = costs.size() / 2;
    nth_element(begin(refunds), begin(refunds) + half, end(refunds), greater {});
    const auto used_refunds = accumulate(cbegin(refunds), cbegin(refunds) + half, 0);

    return price_if_all_to_a - used_refunds;
  }
};