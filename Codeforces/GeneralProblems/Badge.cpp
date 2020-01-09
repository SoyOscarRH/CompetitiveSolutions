#include <iostream>
#include <vector>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  auto numStudents = int {};
  cin >> numStudents;

  auto studentsWithHole = std::vector<bool>(numStudents, false);
  auto nextStudents = std::vector<int>(numStudents);

  for (auto i {0}; i < numStudents; ++i) cin >> nextStudents[i];

  for (auto i {0}; i < numStudents; ++i) {
    studentsWithHole.assign(studentsWithHole.size(), false);
    auto current {i};
    while (not studentsWithHole[current]) {
      studentsWithHole[current] = true;
      current = nextStudents[current] - 1;
    }

    cout << current + 1 << ' ';
  }

  cout << endl;

  return 0;
}