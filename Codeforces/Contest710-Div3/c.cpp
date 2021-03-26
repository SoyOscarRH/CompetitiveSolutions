#include <iostream>
#include <string>

using namespace std;

auto solve(const string& a, const string& b) -> int {
  const auto initial = min<int>(a.size(), b.size());
  for (auto candidate_size = initial; candidate_size > 0; candidate_size -= 1) {
    const auto a_limit = a.size() - candidate_size;
    const auto b_limit = b.size() - candidate_size;

    for (auto i = 0; i <= a_limit; ++i) {
      for (auto j = 0; j <= b_limit; ++j) {
        auto option = true;
        for (auto k = 0; k < candidate_size; ++k) {
          if (a.at(i + k) != b.at(j + k)) {
            option = false;
            break;
          }
        }

        if (option) {
          return a_limit + b_limit;
        }
      }
    }
  }

  return a.size() + b.size();
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }

  return 0;
}