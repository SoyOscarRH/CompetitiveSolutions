#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const auto endline = '\n';

struct student_t {
  string name;
  bool available = true;
};

auto get_num_words() -> int {
  auto data = string {};
  getline(cin, data);
  return count(begin(data), end(data), ' ') + 1;
}

auto get_student() -> vector<student_t> {
  int num_students;
  cin >> num_students;
  auto students = vector<student_t>(num_students);
  for (auto& s : students) cin >> s.name;

  return students;
}

int main() {
  ios::sync_with_stdio(false);

  const auto number_of_words = get_num_words();
  auto students = get_student();

  bool choosing_team1 = true;
  auto team1 = vector<string> {}, team2 = vector<string> {};

  auto get_next = [&](const int x) { return (x + 1) % students.size(); };

  auto i = 0, num_student_passed = 0;
  for (int available = students.size(); available > 0; i = get_next(i)) {
    auto& student = students[i];
    if (not student.available) continue;
    num_student_passed++;

    if ((num_student_passed % number_of_words) != 0) continue;
    auto& team = choosing_team1 ? team1 : team2;
    team.push_back(student.name);

    num_student_passed = 0;
    student.available = false;
    available--;
    choosing_team1 = !choosing_team1;
  }

  cout << team1.size() << endline;
  for (const string names : team1) cout << names << endline;

  cout << team2.size() << endline;
  for (const string names : team2) cout << names << endline;
}