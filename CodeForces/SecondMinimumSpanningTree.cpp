#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename ID = int, typename numCount = int, typename numRank = int>
class UnionFind {
 private:
  std::vector<numCount> parent;
  std::vector<numCount> nodesInComponent;
  std::vector<numRank> rank;

  auto findParentNode(ID node) -> ID {
    ID& nodeParent = parent[node];
    if (node == nodeParent) return node;

    nodeParent = findParentNode(nodeParent);
    return nodeParent;
  }

 public:
  UnionFind(ID numNodes) : nodesInComponent(numNodes, 1), rank(numNodes, 0) {
    parent.resize(numNodes);
    while (--numNodes) parent[numNodes] = numNodes;
  }

  auto existPath(ID nodeA, ID nodeB) -> bool {
    return findParentNode(nodeA) == findParentNode(nodeB);
  }

  auto numberOfElementsInAComponent(ID node) -> numCount {
    return nodesInComponent[findParentNode(node)];
  }

  auto joinComponents(ID nodeA, ID nodeB) -> void {
    ID setA {findParentNode(nodeA)}, setB {findParentNode(nodeB)};

    if (setA == setB) return;
    if (rank[setA] < rank[setB]) std::swap(setA, setB);

    parent[setB] = setA;
    nodesInComponent[setA] += nodesInComponent[setB];

    if (rank[setA] == rank[setB]) ++rank[setA];
  }
};

template <typename nodeID, typename weight>
struct node {
  nodeID from, to;
  weight cost;
  void print() const {
    cout << from + 1 << " " << to + 1;
    cout << " " << cost << endl;
  }
};

template <typename nodeID, typename weight>
class PonderateGraph {
  using node = node<nodeID, weight>;

 public:
  std::vector<node> edges;

  auto addEdge(nodeID from, nodeID to, weight cost) -> void {
    edges.push_back({from, to, cost});
  }

  auto Kruskal(nodeID nodesInGraph) -> void {
    auto minimumWeight = weight {}, minimumWeight2 = weight {-1};
    vector<node> inMST {};
    inMST.reserve(nodesInGraph);
    UnionFind<nodeID> graphInfo {nodesInGraph + 1};
    auto sortNodes = [](node& n1, node& n2) { return n1.cost < n2.cost; };
    sort(edges.begin(), edges.end(), sortNodes);

    for (const node& edge : edges) {
      if (graphInfo.existPath(edge.to, edge.from)) continue;
      minimumWeight += edge.cost;
      graphInfo.joinComponents(edge.to, edge.from);
      inMST.push_back(edge);
      if (graphInfo.numberOfElementsInAComponent(edge.to) == nodesInGraph)
        break;
    }

    cout << minimumWeight << " ";

    random_shuffle(inMST.begin(), inMST.end());

    for (const node& excludedEdge : inMST) {
      auto graphInfo2 = UnionFind<nodeID> {nodesInGraph + 1};

      nodeID nodesInThis {};
      minimumWeight = 0;
      for (const node& edge : edges) {
        if (excludedEdge.cost == edge.cost and
            excludedEdge.from == edge.from and excludedEdge.to == edge.to)
          continue;

        if (not graphInfo2.existPath(edge.to, edge.from)) {
          minimumWeight += edge.cost;
          graphInfo2.joinComponents(edge.to, edge.from);
          nodesInThis = graphInfo2.numberOfElementsInAComponent(edge.to);
          if (minimumWeight > minimumWeight2 and minimumWeight2 != -1) break;
          if (nodesInThis == nodesInGraph) break;
        }
      }

      if (nodesInThis == nodesInGraph)
        minimumWeight2 = minimumWeight2 == -1
                             ? minimumWeight
                             : min(minimumWeight2, minimumWeight);
    }

    cout << minimumWeight2 << "\n";
  };
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int vertices, edges;
  cin >> vertices >> edges;

  PonderateGraph<int, long long> p {};
  int from, to;
  long long weight;

  p.edges.reserve(edges);
  for (int e {}; e < edges; ++e) {
    cin >> from >> to >> weight;
    p.addEdge(from - 1, to - 1, weight);
  }

  p.Kruskal(vertices);

  return 0;
}