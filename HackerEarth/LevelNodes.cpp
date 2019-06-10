#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main(int argc, char const* argv[]) {
  using namespace std;

  std::ios::sync_with_stdio(false);

  int NumberOfNodes;
  vector<vector<int> > Tree;

  // GET THE DATA
  cin >> NumberOfNodes;
  Tree.resize(NumberOfNodes + 1);

  for (int i = 0; i < NumberOfNodes - 1; ++i) {
    int Egde1, Egde2;
    cin >> Egde1 >> Egde2;
    Tree[Egde1].push_back(Egde2);
    Tree[Egde2].push_back(Egde1);
  }

  int DesiredLevel;
  cin >> DesiredLevel;

  // BFS
  int ActualNode = 1;

  queue<int> AuxiliarQueue({1});
  vector<int> DeepLevel(NumberOfNodes + 1);
  vector<bool> Visited(NumberOfNodes + 1, false);

  int NodesInSelectedLevel = 0;
  Visited[ActualNode] = true;
  DeepLevel[ActualNode] = 1;

  while (!AuxiliarQueue.empty()) {
    if (DeepLevel[ActualNode] > DesiredLevel) break;

    ActualNode = AuxiliarQueue.front();
    AuxiliarQueue.pop();

    for (int NewNode : Tree[ActualNode]) {
      if (Visited[NewNode] == true) continue;

      DeepLevel[NewNode] = DeepLevel[ActualNode] + 1;

      if (DeepLevel[NewNode] == DesiredLevel) NodesInSelectedLevel++;

      AuxiliarQueue.push(NewNode);

      Visited[NewNode] = true;
    }
  }

  cout << NodesInSelectedLevel << "\n";
}