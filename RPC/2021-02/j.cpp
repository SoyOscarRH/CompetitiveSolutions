#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

using num = int64_t;

struct book {
  double pages, day_to_read_it, rate;
};

auto is_possible(const double speed, const vector<book>& books) -> int {
  num pages_left = 0;
  num current_day = 0;
  for (const auto b : books) {
    const auto pages_to_read = b.pages - pages_left;
    const auto days_will_take = ceil(pages_to_read / speed);
    pages_left = (speed * days_will_take) - pages_to_read;
    current_day += days_will_take;
    if (current_day > b.day_to_read_it) return false;
  }

  return true;
}

auto find_min_possible(const vector<book>& books) -> num {
  int low = 1;
  int high = numeric_limits<int>::max();

  while (low <= high) {
    const auto current = low + (high - low) / 2;
    if (is_possible(current, books)) {
      high = current;
      if (!is_possible(current - 1, books)) { return current; }
    } else {
      low = current + 1;
    }
  }

  return 0;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  num num_books, possible_to_be_late;
  cin >> num_books >> possible_to_be_late;

  auto raw_books = vector<book>(num_books);
  for (auto& b : raw_books) {
    cin >> b.pages >> b.day_to_read_it;
    b.rate = b.pages / b.day_to_read_it;
  }

  partial_sort(begin(raw_books), begin(raw_books) + possible_to_be_late, end(raw_books),
               [](const book b1, const book b2) { return b1.rate > b2.rate; });

  auto books = vector<book>(begin(raw_books) + possible_to_be_late, end(raw_books));
  sort(begin(books), end(books),
       [](const book b1, const book b2) { return b1.day_to_read_it < b2.day_to_read_it; });

  cout << find_min_possible(books) << endl;

  return 0;
}