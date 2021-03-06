#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

using num = int64_t;

struct book {
  num pages, day_to_read_it;
};

auto is_possible(const num speed, const num possible_to_be_late, const vector<book>& books) -> int {
  num pages_left = 0;
  num current_day = 0;
  for (const auto b : books) {
    const auto pages_to_read = b.pages - pages_left;
    const auto days = ceil(static_cast<double>(pages_to_read) / static_cast<double>(speed));
    pages_left = (speed * days) - pages_to_read;
    current_day += days;
    if (current_day > b.day_to_read_it) return false;
  }

  return true;
}

auto find_min_possible(const num late, const vector<book>& books) -> num {
  auto low = num {1};
  auto high = numeric_limits<num>::max();

  while (low <= high) {
    const auto current = low + (high - low) / 2;
    if (!is_possible(current, late, books)) {
      low = current + 1;
    } else {
      high = current;
      if (!is_possible(current - 1, late, books)) { return current; }
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
  for (auto& b : raw_books) { cin >> b.pages >> b.day_to_read_it; }
  partial_sort(
      begin(raw_books), begin(raw_books) + possible_to_be_late, end(raw_books),
      [](const book b1, const book b2) {
        const auto t1 = static_cast<double>(b1.pages) / static_cast<double>(b1.day_to_read_it);
        const auto t2 = static_cast<double>(b2.pages) / static_cast<double>(b2.day_to_read_it);

        return t1 > t2;
      });

  auto books = vector<book>(begin(raw_books) + possible_to_be_late, end(raw_books));
  sort(begin(books), end(books),
       [](const book b1, const book b2) { return b1.day_to_read_it < b2.day_to_read_it; });

  cout << find_min_possible(possible_to_be_late, books) << endl;

  return 0;
}