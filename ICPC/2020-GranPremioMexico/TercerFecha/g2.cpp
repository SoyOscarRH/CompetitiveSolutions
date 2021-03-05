#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;
using num = long long;
using unum = unsigned long long;

constexpr auto endline = '\n';

struct my_range {
  num from, to, gold;
  my_range(num gold, num from, num to) : gold {gold}, to {to}, from {from} {}
};

auto max_gold(const num section_id, const vector<my_range>& sections,
              map<num, num>& how_much_gold_since) -> num {
  if (section_id >= sections.size()) return 0;

  const auto it = how_much_gold_since.find(section_id);

  if (it != end(how_much_gold_since)) { return it->second; }

  auto section = sections.at(section_id);

  num take = 0;
  const auto start = min(section_id + section.to, num(sections.size()) - 1);
  for (num i = start; i >= section_id + section.from; --i) {
    take = max(take, max_gold(i, sections, how_much_gold_since));
  }

  const auto result = take + section.gold;
  how_much_gold_since[section_id] = result;

  return result;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  num n;
  cin >> n;

  auto sections = vector<my_range> {};
  sections.emplace_back(0, 1, n + 3);
  for (auto i = 0; i < n; ++i) {
    num from, to, gold;
    cin >> gold >> from >> to;
    sections.emplace_back(gold, from, to);
  }

  auto memo = map<num, num> {};
  cout << max_gold(0, sections, memo) << endl;

  return 0;
}