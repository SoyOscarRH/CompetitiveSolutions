#include <iostream>
#include <string>

using namespace std;

auto sizeOfLists(string data) -> pair<int, int> {
  int delante {}, detras {};

  for (int i {}; i < data.size(); ++delante) {
    if (data[i] == '1') i += 4;
    else i += 3;
  }

  for (int i = data.size() - 1; i >= 0; ++detras) {
    if (data[i] == '1') i -= 4;
    else i -= 3;
  }

  return {delante, detras};
}


int main () {
  string data {};
  cin >> data;

  pair<int, int> result = sizeOfLists(data);
  cout << result.first << " " << result.second << endl;
}