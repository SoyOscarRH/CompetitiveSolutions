#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char SHEEP {'S'}, DOG {'D'}, WOLF {'W'};

auto putADog(char& animal) -> void {
  switch (animal) {
    case WOLF:
      cout << "NO" << endl;
      exit(0);
      break;

    case SHEEP:
      break;

    default:
      animal = DOG;
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);

  auto rows = int {}, columns = int {};
  auto helper = string {};
  cin >> rows >> columns;
  helper.reserve(columns);

  auto pasture = vector<string>(rows);
  for (auto& level : pasture) {
    cin >> level;
  }

  for (auto row {0}; row < rows; ++row) {
    for (auto column {0}; column < columns; ++column) {
      auto current {pasture[row][column]};
      if (current != SHEEP) continue;

      // moves
      if (row + 1 < rows) putADog(pasture[row + 1][column]);
      if (row - 1 >= 0) putADog(pasture[row - 1][column]);
      if (column + 1 < columns) putADog(pasture[row][column + 1]);
      if (column - 1 >= 0) putADog(pasture[row][column - 1]);
    }
  }

  cout << "YES" << '\n';

  for (auto& level : pasture) {
    for (auto& element : level) {
      cout << element;
    }
    cout << '\n';
  }

  return 0;
}