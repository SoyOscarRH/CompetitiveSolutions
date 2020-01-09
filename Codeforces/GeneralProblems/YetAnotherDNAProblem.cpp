#include <array>
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
auto main() -> int {
  auto seen = array<int, 256> {};
  seen.fill(0);
 
  int a;
  cin >> a;
 
  string DNA;
  cin >> DNA;
 
  for (auto gen : DNA) ++seen[gen];
 
 
 
  cout << min({seen['A'], seen['C'], seen['G'], seen['T']}) << endl;
  return 0;
}