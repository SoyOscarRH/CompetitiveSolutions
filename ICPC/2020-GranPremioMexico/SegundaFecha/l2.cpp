#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';
auto is_zero(const int x) { return x == 0; }

auto reset_bucket(vector<int>& bucket, const string& to_find) {
  for (auto& x : bucket) x = 0;
  for (auto letter : to_find) { --bucket[letter]; }
}

auto search(const vector<string>& board, const string& to_find,
            map<string, set<pair<int, int>>>& seen) {
  auto bucket = vector<int>(256, 0);
  auto current = list<char> {};

  for (auto i = 0; i < board.size(); ++i) {
    current = list<char> {};
    reset_bucket(bucket, to_find);

    for (auto j = 0; j < board[0].size(); ++j) {
      const auto to_add = board[i][j];
      ++bucket[to_add];
      current.push_back(to_add);
      if (current.size() > to_find.size()) {
        const auto to_delete = current.front();
        current.pop_front();
        --bucket[to_delete];
      }

      if (all_of(begin(bucket), end(bucket), is_zero)) {
        for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i, j - k}); }
      }
    }
  }

  for (auto j = 0; j < board[0].size(); ++j) {
    current = list<char> {};
    reset_bucket(bucket, to_find);

    for (auto i = 0; i < board.size(); ++i) {
      const auto to_add = board[i][j];
      ++bucket[to_add];
      current.push_back(to_add);
      if (current.size() > to_find.size()) {
        const auto to_delete = current.front();
        current.pop_front();
        --bucket[to_delete];
      }

      if (all_of(begin(bucket), end(bucket), is_zero)) {
        for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i - k, j}); }
      }
    }
  }

  for (auto i = 0; i < board.size(); ++i) {
    for (auto j = 0; j < board[0].size(); ++j) {
      current = list<char> {};
      reset_bucket(bucket, to_find);

      for (auto i2 = i, j2 = j; i2 < board.size() and j2 < board[0].size(); ++i2, ++j2) {
        const auto to_add = board[i2][j2];
        ++bucket[to_add];
        current.push_back(to_add);
        if (current.size() > to_find.size()) {
          const auto to_delete = current.front();
          current.pop_front();
          --bucket[to_delete];
        }
        if (all_of(begin(bucket), end(bucket), is_zero)) {
          for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i2, j2}); }
        }
      }
    }
  }

  for (auto i = 0; i < board.size(); ++i) {
    for (auto j = 0; j < board[0].size(); ++j) {
      current = list<char> {};
      reset_bucket(bucket, to_find);

      for (auto i2 = i, j2 = j; i2 < board.size() and j2 < board[0].size(); --i2, --j2) {
        const auto to_add = board[i2][j2];
        ++bucket[to_add];
        current.push_back(to_add);
        if (current.size() > to_find.size()) {
          const auto to_delete = current.front();
          current.pop_front();
          --bucket[to_delete];
        }

        if (all_of(begin(bucket), end(bucket), is_zero)) {
          for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i2, j2}); }
        }
      }
    }
  }

  for (auto i = 0; i < board.size(); ++i) {
    for (auto j = 0; j < board[0].size(); ++j) {
      current = list<char> {};
      reset_bucket(bucket, to_find);

      for (auto i2 = i, j2 = j; i2 < board.size() and j2 < board[0].size(); --i2, --j2) {
        const auto to_add = board[i2][j2];
        ++bucket[to_add];
        current.push_back(to_add);
        if (current.size() > to_find.size()) {
          const auto to_delete = current.front();
          current.pop_front();
          --bucket[to_delete];
        }

        if (all_of(begin(bucket), end(bucket), is_zero)) {
          for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i2, j2}); }
        }
      }
    }
  }
  for (auto i = 0; i < board.size(); ++i) {
    for (auto j = 0; j < board[0].size(); ++j) {
      current = list<char> {};
      reset_bucket(bucket, to_find);

      for (auto i2 = i, j2 = j; i2 < board.size() and j2 < board[0].size(); ++i2, --j2) {
        const auto to_add = board[i2][j2];
        ++bucket[to_add];
        current.push_back(to_add);
        if (current.size() > to_find.size()) {
          const auto to_delete = current.front();
          current.pop_front();
          --bucket[to_delete];
        }

        if (all_of(begin(bucket), end(bucket), is_zero)) {
          for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i2, j2}); }
        }
      }
    }
  }

  for (auto i = 0; i < board.size(); ++i) {
    for (auto j = 0; j < board[0].size(); ++j) {
      current = list<char> {};
      reset_bucket(bucket, to_find);

      for (auto i2 = i, j2 = j; i2 < board.size() and j2 < board[0].size(); --i2, ++j2) {
        const auto to_add = board[i2][j2];
        ++bucket[to_add];
        current.push_back(to_add);
        if (current.size() > to_find.size()) {
          const auto to_delete = current.front();
          current.pop_front();
          --bucket[to_delete];
        }

        if (all_of(begin(bucket), end(bucket), is_zero)) {
          for (auto k = 0; k < to_find.size(); ++k) { seen[to_find].insert({i2, j2}); }
        }
      }
    }
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n_rows, n_cols, n_words;

  cin >> n_rows >> n_cols;
  auto grid = vector<string>(n_rows);
  for (auto& line : grid) cin >> line;

  cin >> n_words;
  auto words = vector<string>(n_words);
  for (auto& word : words) cin >> word;

  auto seen = map<string, set<pair<int, int>>> {};

  for (const auto& word : words) search(grid, word, seen);
  auto points = map<pair<int, int>, int> {};

  for (const auto& [word, word_points] : seen) {
    for (const auto& point : word_points) { ++points[point]; }
  }

  for (const auto [key, value] : points) {
    if (value > 1) { cout << key.first << " " << key.second << endl; }
  }
}