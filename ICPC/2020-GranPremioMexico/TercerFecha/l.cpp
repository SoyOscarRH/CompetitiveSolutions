#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto get_num_generators(const vector<string>& words) -> int {
  auto already_seen_it_is_generated = vector<bool>(words.size(), false);

  auto possible_generated = vector<string> {};
  for (const auto& word : words) { possible_generated.emplace_back(std::move(word + word)); }

  auto generators_used = 0;
  for (auto i = 0; i < words.size(); ++i) {
    const auto& possible_generator = words[i];
    if (already_seen_it_is_generated[i]) continue;

    auto i_am_a_generator = false;
    for (auto j = i; j < possible_generated.size(); ++j) {
      if (already_seen_it_is_generated[j]) continue;

      const auto& generated = possible_generated[j];

      const auto can_be_generated = possible_generator.size() * 2 == generated.size() and
                                    generated.find(possible_generator) != std::string::npos;

      if (i == j or can_be_generated) {
        i_am_a_generator = true;
        already_seen_it_is_generated[j] = true;
      }
    }

    if (i_am_a_generator) { generators_used += 1; }
  }

  return generators_used;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  auto words = vector<string>(n);
  for (auto& word : words) cin >> word;
  cout << get_num_generators(words) << endl;

  return 0;
}
