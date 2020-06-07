struct Solution {
  auto reconstructQueue(vector<vector<int>>& people) -> vector<vector<int>> {
    sort(begin(people), end(people), less_height);

    auto result = vector<vector<int>> {};
    for (auto i = 0; i < people.size(); ++i) 
      result.insert(begin(result) + people[i][1], people[i]);

    return result;
  }

  static auto less_height(const vector<int>& p1, const vector<int>& p2) -> bool {
    if (p1[0] != p2[0]) return p1[0] > p2[0];
    return p1[1] < p2[1];
  }
};