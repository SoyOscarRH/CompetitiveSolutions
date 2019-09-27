#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

inline auto valid(int x) -> bool { return x >= 0; };

int main() {
  auto tests_cases = 0;
  cin >> tests_cases;

  auto queries = vector<int>(tests_cases);
  for (auto& query : queries) cin >> query;

  auto max_input = *max_element(begin(queries), end(queries));
  auto dp =
      vector<vector<bool>>(max_input + 1, vector<bool>(max_input + 1, false));

  for (size_t stone = 0; stone <= max_input; stone++) {
    for (size_t j = stone + 1; stone <= max_input; stone++) {
      for (size_t stone = 0; stone <= max_input; stone++) {
      }
    }
  }

  cout << endl;

  return 0;
}