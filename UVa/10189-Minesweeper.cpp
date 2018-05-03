// ======================================================================
// =========================     UVa: 10189    ==========================
// ======================================================================
#include <iostream>
#include <vector>

using namespace std;          

int main(int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    int CurrentTestCase = 1;

    while (cin >> m >> n) {
        if (m == 0 or n == 0) break;
        else if (CurrentTestCase != 1) cout << "\n";

        vector< vector<char> > Input(m, vector<char>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> Input[i][j];

        cout << "Field #" << CurrentTestCase++ << ":\n";

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (Input[i][j] == '*') {
                    cout << "*";
                    continue;
                }
                int AdjacentBombs = 0;
                vector< pair<int, int> > Moves = {
                    {-1, -1},
                    {-1,  0},
                    { 0, -1},
                    { 0,  1},
                    { 1,  0},
                    { 1,  1},
                    { 1, -1},
                    {-1,  1},
                }; 
                
                for (auto& Move: Moves) {
                    int Newi = i + Move.first;
                    int Newj = j + Move.second;

                    if (Newi < 0 or Newi >= m or Newj < 0 or Newj >= n)
                        continue;

                    if (Input[Newi][Newj] == '*') AdjacentBombs++;
                }

                cout << AdjacentBombs;
            }
            cout << "\n";
        }
    }

    return 0;
}