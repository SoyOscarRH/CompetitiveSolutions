class Solution {
  map<string, multiset<string>> targets;
  vector<string> route;

  auto visit(const string& airport) -> void {
    while (targets[airport].size()) {
      const auto next = *targets[airport].begin();
      targets[airport].erase(begin(targets[airport]));
      visit(next);
    }
    route.push_back(airport);
  }

 public:
  auto findItinerary(vector<vector<string>>& tickets) -> vector<string> {
    for (const auto& ticket : tickets) targets[ticket[0]].insert(ticket[1]);

    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
  }
};