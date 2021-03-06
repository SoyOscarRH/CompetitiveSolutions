#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct node {
  double x;
  double y;
  bool visited;
  node() : visited(false) {}
};

auto distance(const node n1, const node n2) -> double {
  const auto q1 = n1.x - n2.x;
  const auto q2 = n1.y - n2.y;
  return (q1 * q1) + (q2 * q2);
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int nJudges, nRepositories, nStorehouses;
  cin >> nJudges >> nRepositories >> nStorehouses;

  auto judges = vector<node>(nJudges);
  auto repos = vector<node>(nRepositories);
  auto stores = vector<node>(nStorehouses);

  for (node& judge : judges) { cin >> judge.x >> judge.y; }

  for (node& repository : repos) { cin >> repository.x >> repository.y; }

  for (node& storehouse : stores) { cin >> storehouse.x >> storehouse.y; }

  double ans = 0;
  for (const auto judge : judges) {
    const auto compare = [&](const node n1, const node n2) {
      if (n1.visited) return false;
      if (n2.visited) return true;

      return distance(n1, judge) < distance(n2, judge);
    };

    const auto repo = min_element(begin(repos), end(repos), compare);
    ans += sqrt(distance(*repo, judge));
    repo->visited = true;

    const auto store = min_element(begin(stores), end(stores), compare);
    ans += sqrt(distance(*store, judge));
    store->visited = true;
  }

  cout << std::fixed << std::showpoint << ans << endl;
  return 0;
}