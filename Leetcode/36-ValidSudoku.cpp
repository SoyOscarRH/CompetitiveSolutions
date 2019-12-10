class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const auto n = 9;
    bool used1[n][n] = {false}, used2[n][n] = {false}, used3[n][n] = {false};

    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        const auto number = board[row][col] - '1';
        if (number == -3) continue;

        const auto grid = ((row / 3) * 3) + col / 3;

        if (used1[row][number] or used2[col][number] or used3[grid][number])
          return false;

        used1[row][number] = used2[col][number] = used3[grid][number] = true;
      }
    }

    return true;
  }
};