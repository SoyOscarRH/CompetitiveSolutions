#include <iostream>
#include <algorithm>

using namespace std;

auto main() -> int {
  long long _A, _B, K;
  cin >> _A >> _B >> K;

  long long A = max(_A, _B);
  long long B = min(_A, _B);

  if (A < K or B < K) {
    cout << 0 << endl;
    return 0;
  }

  if (B - K < K) {
    cout << A / K << endl;
    return 0;
  }

  
  cout << 2 * (A / K) + 2 * (B / K) - 4<< endl;

  return 0;
}
