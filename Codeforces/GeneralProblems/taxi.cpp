#include <array>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  int num_groups;
  cin >> num_groups;
  auto groups = vector<int>(num_groups);
  for (auto& group : groups) { cin >> group; }

  auto num_groups_of = array<int, 5> {};
  for (const auto group : groups) { ++num_groups_of[group]; }

  auto taxis = 0;
  taxis += num_groups_of[4];
  {
    taxis += num_groups_of[3];
    num_groups_of[1] -= num_groups_of[3];
  }

  {
    taxis += num_groups_of[2] / 2;

    const auto num_taxis_2_no_idea = num_groups_of[2] % 2;
    taxis += num_taxis_2_no_idea;
    num_groups_of[1] -= (num_taxis_2_no_idea * 2);
  }

  if (num_groups_of[1] > 0) {
    const auto num_taxis_1111 = num_groups_of[1] / 4;
    const auto num_taxis_just_ones = num_groups_of[1] % 4 != 0 ? 1 : 0;

    taxis += num_taxis_1111 + num_taxis_just_ones;
  }

  cout << taxis << endl;

  return 0;
}