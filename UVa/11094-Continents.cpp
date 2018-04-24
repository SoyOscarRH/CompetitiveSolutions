#include <iostream>
#include <string.h>

using namespace std;


int n, m, i, j, Solution, AreaOfContinent;

char Map[21][21];
char CharacterForLand;
bool Visited[21][21];

void DFS(int x, int y) {
    
    if (y < 0) y = m - 1;
    if (y >= m) y = 0;

    if (x < 0 or x >= n) return;
    if (Visited[x][y] or Map[x][y] != CharacterForLand) return;

    Visited[x][y] = true;

    AreaOfContinent += 1;

    DFS(x + 1, y + 0);
    DFS(x + 0, y + 1);
    DFS(x - 1, y + 0);
    DFS(x - 0, y - 1);
}


int main() {
    
    ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        
        memset(Visited, false, sizeof(Visited));

        for(i = 0; i < n; i++)
            cin >> Map[i];

        cin >> i >> j;
        CharacterForLand = Map[i][j];

        DFS(i, j);
        Solution = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                AreaOfContinent = 0;
                DFS(i, j);
                
                if (AreaOfContinent > Solution) Solution = AreaOfContinent;
            }
        }

        cout << Solution << "\n";
    }
    return 0;
}