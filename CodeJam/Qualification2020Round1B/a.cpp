#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long long;

inline auto same_parity(num a, num b) { return not((a & 1) xor (b & 1)); }

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  auto answer = string {};
  auto a = 0ll, b = 0ll;
  cin >> a >> b;

  const auto sign_a = a >= 0, sign_b = b >= 0;
  a = abs(a), b = abs(b);

  while (a or b) {
    if (same_parity(a, b)) {
      answer = "IMPOSSIBLE";
      break;
    }

    if (a & 1) {
      b /= 2;

      if (b == 0 and a == 1) {
        answer += (sign_a ? 'E' : 'W');
        break;
      }

      if (same_parity((a + 1) / 2, b)) {
        --a;
        answer += (sign_a ? 'E' : 'W');
      } else {
        ++a;
        answer += (sign_a ? 'W' : 'E');
      }
      a /= 2;
    } else {
      a /= 2;

      if (a == 0 and b == 1) {
        answer += (sign_b ? 'N' : 'S');
        break;
      }

      if (same_parity(a, (b + 1) / 2)) {
        --b;
        answer += (sign_b ? 'N' : 'S');
      } else {
        ++b;
        answer += (sign_b ? 'S' : 'N');
      }
      b /= 2;
    }
  }

  cout << answer << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto test = 1; test <= tests; ++test) solve(test);

  return 0;
}