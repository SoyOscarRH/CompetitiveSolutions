#include <vector>
#include <iostream>

int main() {
    using namespace std;

    int m;
    cin >> m;
    char symbol {'*'}, endLine {'\n'};

    // Empty Matrix
    int xAxis {2*m + 1}, yAxis {m};
    vector< vector<char> > logo (yAxis, vector<char>(xAxis, ' '));

    // Line by line
    for (int x = 0; x < m; x++) logo[yAxis - 1][x] = symbol;
    for (int x = m + 1; x <= 2 * m; x++) logo[0][x] = symbol;
    for (int y = 0; y < m; y++) logo[y][xAxis - 1] = symbol;
    for (int y = 0; y < m; y++) logo[y][0] = symbol;
    for (int y = 0; y < m; y++) logo[y][m - 1] = symbol;
    for (int y = 0; y < m; y++) logo[y][m + 1] = symbol;

    // Line by line
    for (auto& line : logo) {
        for (auto pixel : line) cout << pixel;
        cout << endLine;
    }

    return 0;
}