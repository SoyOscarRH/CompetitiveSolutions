#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

using num = int64_t;


auto main() -> int {
  ios::sync_with_stdio(false);

  auto books = vector<int>  {1, 232, 121, 32212, 831212, 2321, 11, 222, 82121212};
  auto k = 2;
  partial_sort(begin(books), begin(books) + k, end(books), [](int i, int j) {
    return i > j;
  });

  for (const auto x : books) {
    cout << x << endl;
  }

  return 0;
}