#include <algorithm>
#include <iostream>
#include <optional>

using namespace std;

auto get_option(int num, int other) -> int {
  for (auto i = 0; i < 10; ++i) {
    const auto candidate = num * 10 + i;
    if (candidate % other == 0) { return candidate; }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);

  int num, result, n;
  cin >> num >> result >> n;

  const auto option = get_option(num, result);
  if (option == -1) {
    cout << -1 << endl;
  } else {
    cout << option << string(n - 1, '0') << endl;
  }

  return 0;
}