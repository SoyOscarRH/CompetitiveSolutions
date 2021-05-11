#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  auto distance_from_origin_of = vector<int>(n + 1);
  auto has_distance_1 = [&](const auto n) { return distance_from_origin_of[n] == 1; };
  for (auto i = 1; i <= n; ++i) { cin >> distance_from_origin_of[i]; }

  auto neighbors_of = unordered_map<int, vector<int>> {};
  for (auto i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    neighbors_of[a].push_back(b);
    neighbors_of[b].push_back(a);
  }

  auto candidates = vector<int> {};
  for (auto i = 1; i <= n; ++i) {
    if (distance_from_origin_of[i] == 0) { candidates.push_back(i); }
  }

  const auto origin = find_if(cbegin(candidates), cend(candidates), [&](auto candidate) {
    return all_of(cbegin(neighbors_of[candidate]), cend(neighbors_of[candidate]), has_distance_1);
  });

  cout << *origin << endl;

  return 0;
}