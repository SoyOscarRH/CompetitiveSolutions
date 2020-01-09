#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <iostream>
 
template <typename number = int, typename index = int>
struct topBottomLCS {
  const std::string A;
  const std::string B;
  const number placeHolder;
  std::vector<std::vector<number>> memorized;
 
  topBottomLCS(std::string A, std::string B, number placeHolder = -1)
      : A {A},
        B {B},
        placeHolder {placeHolder},
        memorized(A.size() + 1,
                  std::vector<number>(B.size() + 1, placeHolder)) {}
 
  auto LCSSince(index i, index j) -> number {
    if (i >= A.size() or j >= B.size()) return 0;
    if (memorized[i][j] != placeHolder) return memorized[i][j];
 
    if (A[i] == B[j]) return memorized[i][j] = LCSSince(i + 1, j + 1) + 1;
    return memorized[i][j] = std::max(LCSSince(i + 1, j), LCSSince(i, j + 1));
  }
};
 
auto main() -> int {
  using namespace std;
 
  string A, B;
  cin >> A >> B;
 
  auto LCS = topBottomLCS<> {A, B, 0};
  cout << LCS.LCSSince(0, 0) << endl;
  return 0;
}