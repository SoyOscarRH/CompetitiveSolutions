class Solution {
 private:
  struct solver {
    const vector<int>& coins;
    map<pair<int, int>, int> memo;

    solver(const vector<int>& coins) : coins {coins} {}

    auto ways(const pair<int, int>& inputs) -> int {
      const auto [amount, index] = inputs;
      if (amount == 0) return 1;
      if (amount < 0) return 0;

      const auto result = memo.find(inputs);
      if (result != end(memo)) return result->second;

      auto total = 0;
      for (auto i = index; i < coins.size(); ++i) total += ways({amount - coins[i], i});

      memo[inputs] = total;
      return total;
    }
  };

 public:
  auto change(const int amount, vector<int>& coins) -> int {
    sort(begin(coins), end(coins), greater {});
    return solver(coins).ways({amount, 0});
  }
};

struct Solution {
  auto change(const int amount, vector<int>& coins) -> int {
    if (amount == 0) return 1;
    if (coins.size() == 0) return 0;

    auto ways = vector<int>(amount + 1, 0);
    ways[0] = 1;

    for (const auto coin : coins) {
      for (auto i = coin; i <= amount; ++i) 
        ways[i] += ways[i - coin];
    }
    return ways[amount];
  }
};