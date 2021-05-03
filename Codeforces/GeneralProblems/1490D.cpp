#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const auto endline = '\n';

struct node_t {
  int val, depthness;
  auto operator<(const node_t& other) const { return this->val < other.val; }
};

using it = vector<node_t>::iterator;
auto calculate_depth(const int depthness, it first, it last) -> void {
  if (first == last) return;

  auto max = max_element(first, last);
  max->depthness = depthness;

  calculate_depth(depthness + 1, first, max);
  calculate_depth(depthness + 1, max + 1, last);
}

auto solve() -> void {
  int num_elements;
  cin >> num_elements;
  auto nodes = vector<node_t>(num_elements);
  for (auto& node : nodes) { cin >> node.val; }

  calculate_depth(0, begin(nodes), end(nodes));
  for (const auto node : nodes) { cout << node.depthness << " "; }

  cout << endline;
}

int main() {
  ios::sync_with_stdio(false);

  int test_cases;
  cin >> test_cases;
  while (test_cases--) { solve(); }

  return 0;
}