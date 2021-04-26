#include <iostream>
#include <vector>

using namespace std;

struct kid_t { int id, candies; };

auto main() -> int {
  int n, steps;
  cin >> n >> steps;

  auto kids_want = vector<kid_t>(n);
  for (auto i = 0; i < n; ++i) {
    cin >> kids_want[i].candies;
    kids_want[i].id = i + 1;
  }

  while (kids_want.size() != 1) {
    auto kid = kids_want.front();
    kid.candies -= steps;

    kids_want.erase(begin(kids_want));
    if (kid.candies > 0) { kids_want.emplace_back(kid); }
  }

  cout << kids_want.front().id << endl;
}