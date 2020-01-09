#include <iostream>
#include <vector>

auto main() -> int {
  using number = unsigned long long;
  using miniNums = unsigned int;

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  number n, times;
  std::cin >> n >> times;

  number numToRead = 1 << n;
  auto nums = std::vector<miniNums> {};
  nums.reserve(numToRead);

  auto x = miniNums {};
  while (numToRead--) {
    std::cin >> x;
    nums.push_back(x);
  }

  if (times % 2 == 1) {
    for (int i = nums.size() - 1; i >= 0; --i) {
      std::cout << nums[i] << ' ';
    }
  } else {
    for (auto n : nums) std::cout << n << ' ';
  }

  std::cout << std::endl;

  return 0;
}
