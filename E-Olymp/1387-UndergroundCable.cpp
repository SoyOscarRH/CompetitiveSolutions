/*======================================================================================================
=============================          GRAPHS REPRESENTATIONS        ===================================
======================================================================================================*/
#include <iostream>                                                             //Include Libraries
#include <vector>                                                               //Include Libraries
#include <utility>                                                              //Include Libraries
#include <queue>                                                                //Include Libraries
#include <stack>                                                                //Include Libraries
#include <cmath>                                                                //Include Libraries
#include <algorithm>                                                            //Include Libraries

using namespace std;                                                            //Bad practice dont do

/*===================================================================
============          GRAPH AS AJDACENT LIST           ==============
===================================================================*/
/* ******************* INFORMATION   **********************
    Info:
    - All the node names are naturals from 0 to NumberOfNodes
    */
class GraphAdjacencyList {

  //===================================
  //========   PRIVATE    =============
  //===================================
  private:
    bool IsBidireccional;                                                       //Is bidireccional graph
    std::vector< std::vector<int> > AdjacencyList;                              //The Adjacency List

  //===================================
  //========    PUBLIC     ============
  //===================================
  public:

    GraphAdjacencyList(int NumberOfNodes, bool IsBidireccional = true):         //Inicializace
        IsBidireccional(IsBidireccional),                                       //Set for directional graph
        AdjacencyList(NumberOfNodes)                                            //Set the adj list to n
    {}                                                                          //Nothing to do


    void AddEdge(int FromThisNode, int ToThisNode) {                            //Add an Edge to the Graph 
        AdjacencyList[FromThisNode].push_back(ToThisNode);                      //Either way, add the info
        if (IsBidireccional) AdjacencyList[ToThisNode].push_back(FromThisNode); //Either way, add the info
    }

    void AddConections(vector< pair<int,int> > Conections) {                    //Add many edges to graph
        for(auto &Edge : Conections)                                            //Foreach edge
            AddEdge(Edge.first, Edge.second);                                   //Add it like normal
    }

    void ShowConsoleInformation() {                                             //Show the information
        for (int i = 0; i < AdjacencyList.size(); ++i) {                        //Foreach Node    
            cout << "Node " << i << ": [";                                      //Show the Node Name
            for (auto &AdjacentNode: AdjacencyList[i])                          //For each conections
                cout << AdjacentNode << " ";                                    //Show each adjacent node
            cout << "]\n";                                                      //Add the space
        }
    }

    //===================================
    //=======    NEW FUNCTIONS    =======
    //===================================
    vector<int> BFS(int InitialNode);                                           //Definition of the BFS!
    vector<int> DFS(int InitialNode);                                           //Definition of the BFS!
};
           


/*===================================================================
============          GRAPH AS AJDACENT LIST           ==============
===================================================================*/
class PonderateGraph {

  //===================================
  //========   PRIVATE    =============
  //===================================
  private:
    int NumberOfNodes;
    vector< pair<double, pair<int, int> > > Edges; 

  //===================================
  //========    PUBLIC     ============
  //===================================
  public:

    PonderateGraph(int NumberOfNodes) {                                         //Graph Constructor
        this->NumberOfNodes = NumberOfNodes;                                    //Add the Number of Nodes
    }                                                                           //Nothing to do

    void AddEdge(int FromThisNode, int ToThisNode, double Weight) {             //Add an Edge to the Graph 
       Edges.push_back({Weight, {FromThisNode, ToThisNode}});                   //Add to vector
    }

    //===================================
    //=======    NEW FUNCTIONS    =======
    //===================================
    pair<double, vector<pair<int, int> > > KruskalMST();                        //Minimal Spanning Tree
};


// =======================================================
// =====       UNION FIND (DISJOINT SET)         =========
// =======================================================
struct UnionFind {
    std::vector<int> SizeComponents;
    std::vector<int> Parent;
    int NumberOfNodes;

    UnionFind(int n) : 
        SizeComponents(n, 1), Parent(n) {
        NumberOfNodes = n;
        while (--n) Parent[n] = n;
    }

    int SuperParent(int u) {
        if (Parent[u] == u) return u;
        return Parent[u] = SuperParent(Parent[u]);
    }

    bool ExistPath(int u, int v) {
        return SuperParent(v) == SuperParent(u);
    }

    void Join(int u, int v) {
        int SuperParentU = SuperParent(u);
        int SuperParentV = SuperParent(v);

        if (SuperParentU == SuperParentV) return;

        Parent[SuperParentU] = SuperParentV;
        SizeComponents[SuperParentV] += SizeComponents[SuperParentU];
    }

    int SizeComponent(int u) {
        return SizeComponents[SuperParent(u)];
    }

};




/*===================================================================
=========     KRUSKAL - MINIMUM SPANNING WEIGHT         =============
===================================================================*/
pair<double, vector<pair<int, int> > > PonderateGraph::KruskalMST() {       //Begin the function
    double MinimumSpanningTree = 0;                                         //Initialize result
 
    sort(Edges.begin(), Edges.end());                                       //Sort in increasing by cost
 
    UnionFind SomeDisjointSet(NumberOfNodes);                               //Create disjoint sets
 
    vector<pair<int, int> > Nodes;

    for (auto Edge : Edges) {                                               //Iterate through all sorted edges
        
        int u = Edge.second.first;                                          //Simple name
        int v = Edge.second.second;                                         //Simple name
 
        int SetU = SomeDisjointSet.SuperParent(u);                          //Get the parent
        int SetV = SomeDisjointSet.SuperParent(v);                          //Get the parent
 
        if (SetU != SetV) {                                                 //Check if edge is creating cycle
            Nodes.push_back({u, v});                                        //Add the node
            MinimumSpanningTree += Edge.first;                              //Update MST weight
            SomeDisjointSet.Join(SetU, SetV);                               //Merge two sets
        }

    }

    return {MinimumSpanningTree, Nodes};
}
 

/*===================================================================
==================           MAIN               =====================
===================================================================*/
int main() {
    std::ios::sync_with_stdio(false);

    while (true) {
        
        int NumberOfCables;
        scanf("%i \n", &NumberOfCables);

        if (NumberOfCables == 0) exit(0);

        int V = NumberOfCables;
        PonderateGraph g(V);

        int Xs[NumberOfCables], Ys[NumberOfCables];
        for (int i = 0; i < NumberOfCables; ++i) {
            scanf("%i %i\n", &Xs[i], &Ys[i]);
        }

        for (int i = 0; i < NumberOfCables; ++i) {
            for (int j = 0; j < NumberOfCables; ++j) {
                g.AddEdge(i, j, sqrt((Xs[i]-Xs[j])*(Xs[i]-Xs[j]) + (Ys[i]-Ys[j])*(Ys[i]-Ys[j])));
            }
        }


        printf("%.2f\n", g.KruskalMST().first);
    }

    return 0;
        
}