#include <vector>

using namespace std;

class Solution {
  template <typename T>
  using matrix = std::vector<std::vector<T>>;
  enum class square : int { start = 1, end = 2, empty = 0, obstacle = -1 };

 private:
  size_t xAxis, yAxis;
  int numberOfWays;

 public:
  auto findWay(matrix<square>& grid, int x, int y, int squaresToVisit) -> void {
    if (x < 0 or x >= xAxis or y < 0 or y >= yAxis) return;

    const auto currentSquare = grid[x][y];

    if (currentSquare == square::obstacle) return;
    if (currentSquare == square::end) {
      if (squaresToVisit == 0) ++numberOfWays;
      return;
    }

    grid[x][y] = square::obstacle;

    const auto toVisit = squaresToVisit - 1;

    findWay(grid, x - 1, y, toVisit);
    findWay(grid, x + 1, y, toVisit);
    findWay(grid, x, y - 1, toVisit);
    findWay(grid, x, y + 1, toVisit);

    grid[x][y] = currentSquare;
  }

  auto uniquePathsIII(matrix<int>& originalGrid) -> int {
    auto& grid = reinterpret_cast<matrix<square>&>(originalGrid);

    xAxis = grid.size(), yAxis = grid[0].size();

    auto squaresToVisit = 1;  // We have to count the start
    auto startingX = 0, startingY = 0;
    for (auto x = 0; x < xAxis; ++x) {
      for (auto y = 0; y < yAxis; ++y) {
        auto element = grid[x][y];
        if (element == square::empty) ++squaresToVisit;
        if (element == square::start) startingX = x, startingY = y;
      }
    }

    numberOfWays = 0;
    findWay(grid, startingX, startingY, squaresToVisit);

    return numberOfWays;
  }
};
