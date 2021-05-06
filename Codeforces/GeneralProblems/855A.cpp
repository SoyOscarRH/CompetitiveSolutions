#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int num_names;
  cin >> num_names;

  auto ya_lo_vi = map<string, bool> {};
  auto nombre = string {};

  while (num_names--) {
    cin >> nombre;
    if (ya_lo_vi[nombre]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
      ya_lo_vi[nombre] = true;
    }
  }

  return 0;
}

auto make_heap(it begin, it last) {
  for (auto current = begin; current != last; ++current) {
    push_heap(begin, current + 1, *current);
  }
} 