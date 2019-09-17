
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;


int main() {
    int n;

    cin >> n;

    auto data = vector<int64_t> (n);
    while (n--) {
      cin >> data[n];
    }

    sort(begin(data), end(data));

    int64_t result = 0;
    int i = 0;
    n = data.size() - 1;
    int ways = data.size() / 2;
    while (ways--) {
      result += (data[i] + data[n - i]) * (data[i] + data[n - i]);
      i++;
    }

  cout << result << endl;

    return 0;
}