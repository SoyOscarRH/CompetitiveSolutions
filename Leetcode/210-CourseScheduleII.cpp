class Solution {
  using graph = vector<vector<int>>;

  auto buildGraph(const int numCourses, vector<vector<int>>& prerequisites) -> graph {
    auto requisite_graph = graph(numCourses);
    for (auto p : prerequisites) requisite_graph[p[1]].push_back(p[0]);
    return requisite_graph;
  }

  bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
    if (todo[node]) return false;
    if (done[node]) return true;
    todo[node] = done[node] = true;

    for (auto neigh : g[node])
      if (!acyclic(g, todo, done, neigh, order)) return false;

    order.push_back(node);
    todo[node] = false;
    return true;
  }

 public:
  auto findOrder(int num_courses, vector<vector<int>>& prerequisites) -> vector<int> {
    auto g = buildGraph(num_courses, prerequisites);
    auto order = vector<int> {};
    auto todo = vector<bool>(num_courses, false), done = vector<bool>(num_courses, false);
    for (auto i = 0; i < num_courses; ++i) {
      if (!done[i] and !acyclic(g, todo, done, i, order)) { return {}; }
    }
    reverse(begin(order), end(order));
    return order;
  }
};