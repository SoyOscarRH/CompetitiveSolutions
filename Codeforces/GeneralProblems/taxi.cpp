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
  {
    taxis += num_groups_of[4];
    num_groups_of[4] = 0;
  }

  {
    const auto taxi_3_1 = min(num_groups_of[3], num_groups_of[1]);
    num_groups_of[3] -= taxi_3_1;
    num_groups_of[1] -= taxi_3_1;

    taxis += taxi_3_1;
    taxis += num_groups_of[3];
  }

  {
    const auto taxi_2_2 = num_groups_of[2] / 2;

    taxis += taxi_2_2;
    num_groups_of[2] -= taxi_2_2 * 2;

    const auto taxi_2_1_1 = min(num_groups_of[2], num_groups_of[1] / 2);
    taxis += taxi_2_1_1;

    num_groups_of[2] -= taxi_2_1_1;
    num_groups_of[1] -= taxi_2_1_1 * 2;

    const auto taxi_2_1 = min(num_groups_of[2], num_groups_of[1]);
    num_groups_of[2] -= taxi_2_1;
    num_groups_of[1] -= taxi_2_1;

    taxis += taxi_2_1;

    taxis += num_groups_of[2];
  }

  {
    const auto taxi_1_1_1_1 = num_groups_of[1] / 4;
    taxis += taxi_1_1_1_1;
    num_groups_of[1] -= taxi_1_1_1_1 * 4;

    const auto taxi_no_idea = num_groups_of[1] != 0 ? 1 : 0;
    taxis += taxi_no_idea;
  }

  cout << taxis << endl;

  return 0;
}