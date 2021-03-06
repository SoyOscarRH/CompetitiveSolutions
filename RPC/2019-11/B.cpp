#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

constexpr int64_t mod = 1e9 + 7;
constexpr int64_t open_parenthesis = -1, close_parenthesis = -2;

auto print_stack(stack<int64_t> to_process) -> void {
  while (not to_process.empty()) {
    const auto element = to_process.top();
    to_process.pop();

    if (element == open_parenthesis)
      cout << "(" << endl;
    else if (element == close_parenthesis)
      cout << ")" << endl;
    else
      cout << element << endl;
  }

  cout << endl;
}

auto reduce_to_number(stack<int64_t>& to_process, bool& suming) -> int64_t {
  auto numbers = vector<int64_t> {};

  while ((not to_process.empty()) and to_process.top() >= 0) {
    numbers.push_back(to_process.top());
    to_process.pop();
  }

  if ((not to_process.empty()) and to_process.top() == open_parenthesis) {
    to_process.pop();
  }

  uint64_t total = 0;
  if (suming) {
    total = 0;

    for (auto num : numbers) {
      total += num;
      if (total > mod) total = total % mod;
    }

  } else {
    total = 1;

    for (auto num : numbers) {
      total *= num;
      if (total > mod) total = total % mod;
    }
  }

  suming = not suming;
  return total % mod;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  auto to_process = stack<int64_t> {};
  auto suming = true;

  string buffer;
  while (cin >> buffer) {
    // print_stack(to_process);

    int64_t element;
    if (buffer[0] == '(') {
      element = open_parenthesis;
      suming = not suming;
    } else if (buffer[0] == ')')
      element = close_parenthesis;
    else
      element = stoll(buffer);

    if (element == close_parenthesis)
      element = reduce_to_number(to_process, suming);
    to_process.push(element);
  }

  // print_stack(to_process);

  const auto result = reduce_to_number(to_process, suming);

  cout << result << endl;

  return 0;
}