#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  uint64_t n, k;
  cin >> n >> k;

  auto distances = vector<double>(n);
  for (auto& distance : distances) {
    double x, y, z;
    cin >> x >> y >> z;
    distance = x * x + y * y + z * z;
  }

  nth_element(begin(distances), begin(distances) + k, end(distances));
  cout << fixed << setprecision(8) << sqrt(distances[k - 1]) << endl;

  return 0;
}