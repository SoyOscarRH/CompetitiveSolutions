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

  auto inSameComponent(id u, id v) -> bool {
    return findComponentID(v) == findComponentID(u);
  }

  auto numberOfElementsConnectedTo(id u) -> int {
    return connected_nodes[findComponentID(u)];
  }

  auto joinComponents(id u, id v) -> void {
    auto setU = findComponentID(u), setV = findComponentID(v);
    if (setU == setV) return;

    if (rank[setU] > rank[setV]) std::swap(setU, setV);

    parent[setU] = setV;
    connected_nodes[setV] += connected_nodes[setU];

    if (rank[setU] == rank[setV]) ++rank[setU];
  }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    const auto m = M.size();
    auto nodes = UnionFind {m};

    for (int i = 0; i < m; ++i) {
      for (int j = i; j < m; ++j) {
        if (not M[i][j]) continue;
        nodes.joinComponents(i, j);
      }
    }

    auto elements = set<int> {};
    for (int i = 0; i < m; ++i) {
      elements.insert(nodes.findComponentID(i));
    }

    return elements.size();
  }
};
