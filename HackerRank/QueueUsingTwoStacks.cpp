#include <iostream>
#include <limits>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class queue_with_stack {
  stack<T> sorted, needing_sorting;

  auto move_around() -> void {
    if (not sorted.empty()) return;
    while (not needing_sorting.empty()) {
      sorted.push(needing_sorting.top());
      needing_sorting.pop();
    }
  }

 public:
  auto push(T&& value) -> void { needing_sorting.push(value); }
  auto pop() -> void { move_around(), sorted.pop(); }

  auto top() -> T {
    move_around();
    return sorted.top();
  }
};

auto main() -> int {
  int num_queries;
  cin >> num_queries;

  auto queries = vector<string>(num_queries);
  cin.ignore(numeric_limits<int>::max(), '\n');
  for (auto& query : queries) { getline(cin, query); }

  auto q = queue_with_stack<int> {};
  for (const auto& query : queries) {
    if (query[0] == '1') { q.push(stoi(query.substr(2))); }
    if (query[0] == '2') { q.pop(); }
    if (query[0] == '3') { cout << q.top() << endl; }
  }

  return 0;
}
