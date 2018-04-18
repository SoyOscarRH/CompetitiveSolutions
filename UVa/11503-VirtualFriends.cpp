// =========================================================================
// =========================     UVa: 11503    =============================
// =========================================================================
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// ====================================================================
// ================       ALREADY SOLVED CODE          ================
// ====================================================================

    // ================================================
    // =====     UNION FIND (DISJOINT SET)     ========
    // ================================================
    /*
        Remember:
            UnionFind needs the number of nodes
            at creation
    */
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


// ====================================================================
// ================              SOLUTION              ================
// ====================================================================
int main() {
    
    std::ios::sync_with_stdio(false);

    int NumberOfCases;
    cin >> NumberOfCases;

    for (int Case = 0; Case < NumberOfCases; ++Case) {

        int NumberOfFriendships;
        cin >> NumberOfFriendships;
        UnionFind Friends(100000);

        map<string, int> FriendID;

        for (int i = 0; i < NumberOfFriendships; ++i) {
            string Friend1, Friend2;
            cin >> Friend1 >> Friend2;


            int Friend1ID;
            if (FriendID.count(Friend1) == 0 ) {
                FriendID[Friend1] = FriendID.size();
                Friend1ID = FriendID.size() - 1;
            } 
            else Friend1ID = FriendID[Friend1];

            int Friend2ID;
            if (FriendID.count(Friend2) == 0 ) {
                FriendID[Friend2] = FriendID.size();
                Friend2ID = FriendID.size() - 1;
            } 
            else Friend2ID = FriendID[Friend2];


            Friends.Join(Friend1ID, Friend2ID);
            cout << Friends.SizeComponent(Friend1ID) << "\n";
        }

    }

    return 0;
}