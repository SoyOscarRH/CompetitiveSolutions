class Solution {
  enum class color : char { white, red, blue };
  using node = int;

 public:
  bool possibleBipartition(const int n, const vector<vector<int>>& edges) {
    auto neighbours_of = vector<vector<node>>(n + 1);
    auto color_of = vector<color>(n + 1, color::white);
    auto explored = vector<bool>(n + 1, false);

    for (const auto& edge : edges) {
      const auto u = edge[0], v = edge[1];
      neighbours_of[u].push_back(v);
      neighbours_of[v].push_back(u);
    }

    for (auto i = 1; i <= n; ++i) {
      if (explored[i]) continue;

      color_of[i] = color::red;
      auto to_visit = queue<int> {{i}};
      while (not to_visit.empty()) {
        const auto u = to_visit.front();
        to_visit.pop();

        if (explored[u]) continue;
        explored[u] = true;

        for (const auto v : neighbours_of[u]) {
          if (color_of[v] == color_of[u]) return false;
          color_of[v] = color_of[u] == color::red ? color::blue : color::red;
          to_visit.push(v);
        }
      }
    }

    return true;
  }
};