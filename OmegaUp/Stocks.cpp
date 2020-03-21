#include <cmath>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int maxProfit() {
  double price;
  int n;
  cin >> price >> n;

  auto max_profit = 0.0;
  auto min_price = numeric_limits<double>::max();

  auto best = 0;
  for (auto i = 0; i < n; i++) {
    cin >> price;
    if (price < min_price) {
      best = i;
      min_price = price;
    }

    max_profit = max(max_profit, price - min_price);
  }

  return best + 1;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) 
  cout << "Case " << i + 1 << ": comprar en dia " << maxProfit() << "\n";

  return 0;
}
