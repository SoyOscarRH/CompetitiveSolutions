#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string data;
  cin >> data;

  uint64_t number_of_e = data.size() - 2;
  data.pop_back();

  string other = string(number_of_e, 'e');

  data += other;

  data += 'y';

  cout << data << endl;

  return 0;
}