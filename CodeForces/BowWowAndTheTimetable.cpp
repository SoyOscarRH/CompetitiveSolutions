#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>


using namespace std::literals;

auto main() -> int {
  auto number = ""s;
  std::cin >> number;

  auto result = std::ceil(number.size() / 2.0);

  auto allAreZeros = std::all_of(begin(number) + 1, end(number),
                                 [](auto digit) { return digit == '0'; });

  if (allAreZeros and number.size() % 2) result -= 1;

  std::cout << result << std::endl;

  return 0;
}
