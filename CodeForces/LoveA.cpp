#include <iostream>
#include <string>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  int numOfA {}, others {};

  std::string data;
  std::cin >> data;

  for (auto letter : data) {
    (letter == 'a') ? ++numOfA : ++others;
  }

  if (numOfA > others)
    cout << data.size() << endl;
  else
    cout << numOfA + (numOfA - 1) << endl;

  return 0;
}