#include <iostream>
#include <numeric>
#include <vector>

/**
 * You have many nodes (with ID's as numbers) and the nodes are connected (ie,
 * node 2 with node 4, 5, 8) Use UnionFind to find if 2 nodes are connected
 * or how many nodes are in a connected to a given node.
 */
template <typename id = int>
class UnionFind {
 private:
  std::vector<id> connected_nodes, parent, rank;

 public:
  UnionFind(id n) : connected_nodes(n, 1), parent(n), rank(n, 0) {
    while (--n) parent[n] = n;
  }

  auto findComponentID(id u) -> id {
    if (parent[u] == u) return u;
    return parent[u] = findComponentID(parent[u]);
  }

  auto inSameComponent(id u, id v) -> bool { return findComponentID(v) == findComponentID(u); }

  auto numberOfElementsConnectedTo(id u) -> int { return connected_nodes[findComponentID(u)]; }

  auto joinComponents(id u, id v) -> void {
    auto setU = findComponentID(u), setV = findComponentID(v);
    if (setU == setV) return;

    if (rank[setU] > rank[setV]) std::swap(setU, setV);

    parent[setU] = setV;
    connected_nodes[setV] += connected_nodes[setU];

    if (rank[setU] == rank[setV]) ++rank[setU];
  }
};

using namespace std;

template <typename T>
auto inline read() -> T {
  auto to_read = T {};
  cin >> to_read;
  return to_read;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto persons = read<int>(), groups = read<int>();

  auto net = UnionFind<> {persons + 1};

  while (groups--) {
    auto num_users_in_group = read<int>(), base_user = 0;

    if (num_users_in_group) {
      base_user = read<int>();
      --num_users_in_group;
    }

    while (num_users_in_group--) net.joinComponents(read<int>(), base_user);
  }

  for (auto i = 1; i <= persons; i++) cout << net.numberOfElementsConnectedTo(i) << " ";

  cout << endl;

  return 0;
}
