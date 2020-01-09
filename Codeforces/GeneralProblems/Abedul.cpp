#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  auto s = string {};
  cin >> s;

  s[s.size() - 1] = 'i';

  s += "co";

  cout << s << endl;

  return 0;
}