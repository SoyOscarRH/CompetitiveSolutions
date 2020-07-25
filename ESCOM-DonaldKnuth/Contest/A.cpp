#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  string data;
  cin >> data;

  for (auto& x : data) {
    if (x == 'O' or x == 'o') {
      x = '0';
    } else if (x == 'I' or x == 'i') {
      x = '1';
    } else if (x == 'Z' or x == 'z') {
      x = '2';
    } else if (x == 'E' or x == 'e') {
      x = '3';
    } else if (x == 'A' or x == 'a') {
      x = '4';
    } else if (x == 'S' or x == 's') {
      x = '5';
    } else if (x == 'G' or x == 'g') {
      x = '6';
    } else if (x == 'T' or x == 't') {
      x = '7';
    } else if (x == 'B' or x == 'b') {
      x = '8';
    }
  }

  cout << data << endl;

  return 0;
}