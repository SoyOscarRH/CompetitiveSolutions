#include <algorithm>
#include <iostream>
#include <vector>

auto main() -> int {
  using namespace std;

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto num_numbers = 0;
  cin >> num_numbers;

  auto numbers = vector<int>(num_numbers);

  for (auto& i : numbers) cin >> i;

  sort(begin(numbers), end(numbers));

  for (auto i : numbers) cout << i << ' ';
  cout << endl;

  return 0;
}
