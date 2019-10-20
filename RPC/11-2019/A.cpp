#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int r, c;
  cin >> r >> c;

  int max1 = INT_MIN, max2 = INT_MIN;

  for (int i = 0, buffer; i < r; ++i) {
    cin >> buffer;
    max1 = max(max1, buffer);
  }

  for (auto i = 0, buffer = 0; i < c; ++i) {
    cin >> buffer;
    max2 = max(max2, buffer);
  }

  cout << (max1 == max2 ? "possible" : "impossible") << endl;

  return 0;
}