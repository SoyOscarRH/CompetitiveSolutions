#include <bits/stdc++.h>

using namespace std;


inline bool checkCell(vector<vector<int>> &matrix, int row, int col) {
    bool checkLeft = matrix[row][col] > matrix[row][col - 1];
    bool checkRight = matrix[row][col] > matrix[row][col + 1];
    bool checkUp = matrix[row][col] < matrix[row + 1][col];
    bool checkDown = matrix[row][col] < matrix[row - 1][col];
    return checkLeft and checkRight and checkUp and checkDown;
}

void findPassPoints(vector<vector<int>> &matrix, set<vector<int>> &passPoints) {
    const int nRows = matrix.size() - 1;
    const int nCols = matrix[0].size() - 1;

    for(int row = 1; row < nRows; row++)
        for(int col = 1; col < nCols; col++)
            if(checkCell(matrix, row, col))
                passPoints.insert({row, col});
           
}

int64_t getBestPath(vector<vector<int>> &matrix, set<vector<int>> &passPoints, int row, int col, int currentPassPoints) {
    const int nRows = matrix.size();
    const int nCols = matrix[0].size();

    if(row < 0 or col < 0 or row >= nRows or col >= nCols) {
        if(col == nCols - 1 and currentPassPoints == 0)
            return 0;
        return INT_MAX;
    }

    const int currentCell = matrix[row][col];

    if(currentCell == -1 or currentPassPoints < 0)
        return INT_MAX;
        
    if(passPoints.find({row, col}) != end(passPoints))
        currentPassPoints--;

    int64_t moveUpRight = getBestPath(matrix, passPoints, row - 1, col + 1, currentPassPoints);
    int64_t moveRight = getBestPath(matrix, passPoints, row, col + 1, currentPassPoints);
    int64_t moveDownRight = getBestPath(matrix, passPoints, row + 1, col + 1, currentPassPoints);

    return min({moveUpRight, moveRight, moveDownRight}) + currentCell;
}

int main() {
    int nRows, nCols, nPasses;
    vector<vector<int>> matrix;
    set<vector<int>> passPoints;

    cin >> nRows >> nCols >> nPasses;
    matrix = vector<vector<int>>(nRows, vector<int>(nCols));

    for(int row = 0; row < nRows; row++)
        for(int col = 0; col < nCols; col++) 
            cin >> matrix[row][col];

    findPassPoints(matrix, passPoints);

    cout << "findPassPoints Finished" << endl;

    int64_t ans = INT_MAX;
    cout << "ans = " << ans << endl;

    for(int row = 0; row < nRows; row++) {
        if(matrix[row][0] != -1) {
            cout << "getBestPath = " << row << ", 0" << endl; 
            ans = min(ans, getBestPath(matrix, passPoints, row, 0, nPasses));
            cout << ans << endl;
        }
    }
    
    cout << "getBestPath finished" << endl;

    cout << "answer = " << ans << endl;
    /*if(ans == INT_MAX)
        cout << "impossible" << endl;
    else 
        cout << ans << endl;*/
}