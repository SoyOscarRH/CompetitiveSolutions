#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  auto data = string {};
  cin >> data;

  auto sum = 0, temporal = 0;
  for (auto c : data) {
    if (c == '.')
      ++temporal;
    else {
      sum = sum xor temporal;
      temporal = 0;
    }
  }

  sum = sum xor temporal;

  auto start = data[0];
  if (all_of(begin(data), end(data), [&](char c) { return c == start; })) 
    sum = 0;

  cout << (sum? "Cat" : "Rabbit") << endl;

  return 0;
}