class Solution {
 public:
  auto isAnagram(const string& s, const string& t) -> bool {
    if (s.size() != t.size()) return false;

    array<int, 26> counts {};
    for (const auto c : s) ++counts[c - 'a'];
    for (const auto c : t) --counts[c - 'a'];

    return all_of(begin(counts), end(counts), [](auto x) { return x == 0; });
  }
};