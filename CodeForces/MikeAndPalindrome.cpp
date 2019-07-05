#include <iostream>
#include <string>

using namespace std;

auto main() -> int {
  auto word = string {};
  cin >> word;

  auto foundAnError = false;

  auto start = word.begin(), end = word.end() - 1;
  for (; start < end; ++start, --end) {
    if (*start == *end) continue;
    if (foundAnError) {
      cout << "NO" << endl;
      return 0;
    }

    foundAnError = true;
  }

  if (word.size() % 2 == 1 and not foundAnError) foundAnError = true;
  auto solution = foundAnError ? "YES" : "NO";
  cout << solution << endl;

  return 0;
}