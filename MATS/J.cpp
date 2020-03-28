#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using num = long double;

constexpr auto endline = '\n';

auto solve_help(const vector<num>& people, int j) -> num {
  auto result = num {};
  for (int i = 0, x = 0; i < people.size(); ++i)
    if (i != j) result += people[i] * pow(num{0.8}, x++);

  return 0.2 * result;
}

auto solve(const vector<num>& people) -> num {
  auto result = num {};
  for (int i = 0; i < people.size(); ++i) {
    result += solve_help(people, i);
  }

  return result / people.size();
}

auto main() -> int {
  auto people = 10;
  cin >> people;

  auto data = vector<num>(people);
  for (auto& p : data) cin >> p;

  std::cout << std::setprecision(16);
  cout << solve_help(data, data.size() + 1) << endl;
  cout << solve(data) << endl;

  return 0;
}