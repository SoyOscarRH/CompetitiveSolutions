#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = uint64_t;

auto main() -> int {
  ios::sync_with_stdio(false);

  num num_strings = 0, n;
  cin >> num_strings;
  auto forbiddens = vector<string>(num_strings);
  for (auto& forbidden : forbiddens) cin >> forbidden;
  cin >> n;

  num valid_nums = 0;
  for (num i = 1; true; ++i) {
    const auto representation = to_string(i);
    auto valid = true;
    for (const auto& forbidden : forbiddens) {
      if (representation.find(forbidden) != std::string::npos) {
        valid = false;
        break;
      }
    }

    if (not valid) continue;
    valid_nums++;

    if (valid_nums == n) {
      cout << representation << endl;
      exit(0);
    }
  }

  return 0;
}