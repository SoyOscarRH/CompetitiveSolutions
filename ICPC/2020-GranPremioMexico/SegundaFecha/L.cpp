#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> frequencies;

struct Node {
    char letter;
    int row;
    int col;

    Node() {

    }

    void setLetter(char _letter) {
        letter = _letter;
    }

    void setCoord(int _row, int _col){
        row = _row, col = _col;
    }
};

bool areEqual(vector<int> &word, vector<int> &substring) {
    for(int i = 0; i < 26; i++)
        if(substring[i] != word[i])
            return false;
    return true;
}

void searchAnagram(string &word, vector<vector<Node*>> &searchSpace) {
    cout << "searching" << endl;
    const int wordSize = word.size();
    const int nRows = searchSpace.size();
    set<pair<int, int>> coordinates;

    vector<int> bucketWord(26, 0);
    

    for(char letter : word)
        bucketWord[letter - 'A']++;

    for(int row = 0; row < nRows; row++) {

        const int size = searchSpace[row].size();
        vector<int> substring(26, 0);

        for(int i = 0; i < size; i++) {
           
            substring[searchSpace[row][i] -> letter - 'A']++;

            if(i >= wordSize)
                substring[searchSpace[row][i - wordSize] -> letter - 'A']--;
            
            cout << (searchSpace[row][i] -> letter) << "";

            if(areEqual(bucketWord, substring)) {
                cout << "are equal" << endl;
                for(int j = i - wordSize + 1; j <= i; j++)
                    coordinates.insert({searchSpace[row][j] -> row, searchSpace[row][j] -> col});
            }
        }
        cout << endl;

    }

    for(pair<int, int> coordinate : coordinates) {
        cout << "(" << coordinate.first << "," << coordinate.second << ")" << endl;
        frequencies[coordinate]++;
    }
}

int main() {
    int nRows, nCols, nWords, countSpecialCells = 0;
    string word;

    vector<vector<Node*>> gridByRows;
    vector<vector<Node*>> gridByCols;

    cin >> nRows >> nCols;
    gridByRows.assign(nRows, vector<Node*>(nCols, new Node()));
    gridByCols.assign(nCols, vector<Node*>(nRows, new Node()));

    char buffer;
    for(int row = 0; row < nRows; row++) {
        for(int col = 0; col < nCols; col++) {
            cin >> buffer;
            cout << buffer << " ";
            gridByRows[row][col] -> setLetter(buffer);// = buffer;
            //gridByRows[row][col] -> row = row;
            //gridByRows[row][col] -> col = col;

            //gridByCols[col][row] -> letter = buffer;
            //gridByCols[col][row] -> row = col;
            //gridByCols[col][row] -> col = row;
        }
        cout << endl;
    }
    
    cin >> nWords;
    while(nWords--) {
        cin >> word;
        searchAnagram(word, gridByRows);
    }

    for(auto &[key, val] : frequencies)
        if(val >= 2)
            countSpecialCells++;

    cout << countSpecialCells << endl;

}