#include <vector>

using namespace std;

class Solution {
  template <typename T>
  using matrix = std::vector<std::vector<T>>;
  enum class squareType : int { start = 1, end = 2, empty = 0, obstacle = -1 };

 private:
  const vector<int> moves {1, -1};
  matrix<bool> visited;
  size_t xAxis, yAxis;
  int numberOfWays;


 public:
  auto findWay(const matrix<squareType>& grid, int x, int y, int squaresToVisit) -> void {
    const auto currentSquare = grid[x][y];
    const auto toVisit = squaresToVisit -1;

    if (currentSquare == squareType::obstacle) return;
    if (currentSquare == squareType::end) {
      if (squaresToVisit == 0) ++numberOfWays;
      return;
    }

    visited[x][y] = true;

    for (auto move : moves) {
      const auto newX = x + move;
      if (0 <= newX and newX < xAxis and not visited[newX][y]) 
          findWay(grid, newX, y, toVisit);
    }

    for (auto move : moves) {
      const auto newY = y + move;
      if (0 <= newY and newY < yAxis and not visited[x][newY]) 
          findWay(grid, x, newY, toVisit);
    }

    visited[x][y] = false;
  }

  auto uniquePathsIII(matrix<int>& originalGrid) -> int {
    const auto& grid = reinterpret_cast<matrix<squareType>&>(originalGrid);

    xAxis = grid.size(), yAxis = grid[0].size();
    visited = matrix<bool>(xAxis, vector<bool>(yAxis, false));

    auto squaresToVisit = 1;    // We have to count the start
    auto startingX = 0, startingY = 0;
    for (auto x = 0; x < xAxis; ++x) {
      for (auto y = 0; y < yAxis; ++y) {
        auto element = grid[x][y];
        if (element == squareType::empty) ++squaresToVisit;
        if (element == squareType::start) startingX = x, startingY = y;
      }
    }

    numberOfWays = 0;
    findWay(grid, startingX, startingY, squaresToVisit);

    return numberOfWays;
  }
};
