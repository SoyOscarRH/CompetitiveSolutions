class Solution {
  int m, n;
  auto isFound(vector<vector<char>>& board, const char* w, const int x, const int y) -> bool {
    if (x < 0 or y < 0 or x >= m or y >= n) return false;
    if (board[x][y] == '\0' or *w != board[x][y]) return false;

    if (*(w + 1) == '\0') return true;
    char t = board[x][y];
    board[x][y] = '\0';

    if (isFound(board, w + 1, x - 1, y) or isFound(board, w + 1, x + 1, y) or
        isFound(board, w + 1, x, y - 1) or isFound(board, w + 1, x, y + 1))
      return true;

    board[x][y] = t;

    return false;
  }

 public:
  auto exist(vector<vector<char>>& board, const string& word) -> bool {
    m = board.size(), n = board[0].size();
    for (auto x = 0; x < m; ++x) {
      for (auto y = 0; y < n; ++y) {
        if (isFound(board, word.c_str(), x, y)) return true;
      }
    }

    return false;
  }
};