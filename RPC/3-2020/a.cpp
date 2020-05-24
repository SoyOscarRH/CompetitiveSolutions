#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long double;

struct data {
  int from, to;
  num p;
};

auto main() -> int {
  ios::sync_with_stdio(false);

  int num_assasins, num_attempts;
  cin >> num_assasins >> num_attempts;

  auto attempts = vector<data>(num_attempts);

  for (auto& a : attempts) cin >> a.from >> a.to >> a.p;

  cout << std::fixed << setprecision(10);

  for (auto assasin = 1; assasin <= num_assasins; ++assasin) {
    auto p_alive = vector<num>(num_assasins, 1.0);

    for (const auto& attempt : attempts) {
      auto dead = 1 - p_alive[attempt.from - 1];
      auto alive = p_alive[attempt.from - 1];

      if (assasin == attempt.from) dead = 0, alive = 1;

      p_alive[attempt.to - 1] *= dead + (alive * (1 - attempt.p));
    }

    cout << p_alive[assasin - 1] << endline;
  }

  return 0;
}
