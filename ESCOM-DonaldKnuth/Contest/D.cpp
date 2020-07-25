#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = uint_fast64_t;
const num mod = 1000000007;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  num n;
  cin >> n;

  auto total = num {0};
  auto current_num = num {1};
  auto k = num {1};

  if (n >= 100413256071523) {
    k = 100413256071523;
    total = 655789394;
    current_num = 10020642;
  }
  if (n >= 1000474644508681) {
    k = 1000474644508681;
    total = 852775158;
    current_num = 31630281;
  }

  if (n >= 10002073007422861) {
    k = 10002073007422861;
    total = 141767939;
    current_num = 100010365;
  }

  if (n >= 100007637351945123) {
    k = 100007637351945123;
    total = 968594331;
    current_num = 316239842;
  }

  if (n >= 1200022497239132073) {
    k = 1200022497239132073;
    total = 67896998;
    current_num = 1095455384;
  }

  if (n >= 150005643670890021) {
    k = 150005643670890021;
    total = 17979405;
    current_num = 387305621;
  }

  while (k <= n) {
    const auto current_times = current_num << 1;
    if (k + current_times <= n) {
      const auto square = current_num * current_num;
      total = (total + square + square) % mod;
      k += current_times;
      ++current_num;
    } else {
      const auto missing = n - k + 1;
      total = (total + current_num * missing) % mod;
      break;
    }
  }

  cout << total << endl;

  return 0;
}