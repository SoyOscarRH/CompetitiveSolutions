#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> houses(n);
    for (int& house : houses) { cin >> house; }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < houses.size(); i += 2) { sum1 += houses[i]; }
    for (int i = 1; i < houses.size(); i += 2) { sum2 += houses[i]; }

    cout << max(sum1, sum2) << endl;
  }

  return 0;
}