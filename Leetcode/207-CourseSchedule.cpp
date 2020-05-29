struct Solution {
  auto canFinish(const int num_courses, const vector<vector<int>>& prerequisites) -> bool {
    auto classes_i_can_take_after = vector<vector<int>>(num_courses, vector<int>());
    auto num_requisites_missing = vector<int>(num_courses, 0);

    for (const auto& prerequisite : prerequisites) {
      const auto to_take = prerequisite[0], requisite = prerequisite[1];
      classes_i_can_take_after[requisite].push_back(to_take);
      ++num_requisites_missing[to_take];
    }

    auto current_courses = queue<int> {};
    for (int i = 0; i < num_courses; ++i)
      if (not num_requisites_missing[i]) current_courses.push(i);

    auto classes_taken = 0;
    while (not current_courses.empty()) {
      const auto course = current_courses.front();
      current_courses.pop();
      ++classes_taken;

      for (const auto next_course : classes_i_can_take_after[course])
        if (--num_requisites_missing[next_course] == 0) current_courses.push(next_course);
    }

    return classes_taken == num_courses;
  }
};