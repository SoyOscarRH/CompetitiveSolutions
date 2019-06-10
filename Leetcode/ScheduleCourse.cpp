#include <iostream>
#include <map>
#include <vector>

using namespace std;

int scheduleCourse(const vector<vector<int>>& _courses) {
  auto courses {_courses};

  std::sort(begin(courses), end(courses),
            [](const vector<int>& c1, const vector<int>& c2) {
              return (c1[1] - c1[0]) - (c2[1] - c2[0]);
            });

  int start {};
  for (auto& course : courses) {
    if (start + course[0] <= course[1]) {
      ++start;
    }
  }

  return start;
}

int main() {
  auto v =
      vector<vector<int>> {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  cout << scheduleCourse(v) << endl;

  return 0;
}