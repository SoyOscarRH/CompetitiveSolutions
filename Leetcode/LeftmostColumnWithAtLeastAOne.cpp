/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
 public:
  auto leftMostColumnWithOne(BinaryMatrix& binaryMatrix) -> int {
    auto answer = -1;
    auto m = binaryMatrix.dimensions()[0], n = binaryMatrix.dimensions()[1];
    auto i = 0, j = n - 1;

    while (i < m and 0 <= j) {
      if (binaryMatrix.get(i, j) == 1)
        answer = j--;
      else
        ++i;
    }

    return answer;
  }
};