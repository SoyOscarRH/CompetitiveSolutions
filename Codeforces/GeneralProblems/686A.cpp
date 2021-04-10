#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  int64_t num_kids, ice_creams, order;
  std::cin >> num_kids >> ice_creams;

  auto angry_kids = 0;
  for (auto i = 0; i < num_kids; ++i) {
    char operation;
    cin >> operation >> order;
    if (operation == '+') { ice_creams += order; } 
    else {
      if (order <= ice_creams) { ice_creams -= order; } 
      else { angry_kids++; }
    }
  }

  cout << ice_creams << " " << angry_kids;

  return 0;
}