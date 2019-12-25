
class Solution {
 public:
  auto merge(vector<int>& A, int m, vector<int>& B, int n) -> void {
    auto a = m - 1, b = n - 1;
    auto i = m + n - 1;
    // calculate the index of the last element of the merged array

    // go from the back by A and B and compare and put to the A element which is
    // larger
    for (; a >= 0 and b >= 0; --i) A[i] = A[a] > B[b] ? A[a--] : B[b--];

    while (b >= 0) A[i--] = B[b--];
  }
};