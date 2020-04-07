struct Solution {
  auto all_zeroes(const array<int, 26>& info) -> bool {
    return all_of(cbegin(info), cend(info), [](const auto x) { return x == 0; });
  }
  auto findAnagrams(const string& s, const string& p) -> vector<int> {
    const auto n = s.size(), m = p.size();
    if (n < m) return {};

    array<int, 26> info {};
    for (const auto letter : p) ++info[letter - 'a'];
    for (int i = 0; i < m; ++i) --info[s[i] - 'a'];

    auto result = all_zeroes(info) ? vector<int> {0} : vector<int> {};

    // substring [left, right)
    for (int right = m, left = 0; right < n; ++right, ++left) {
      --info[s[right] - 'a'];
      ++info[s[left] - 'a'];
      if (all_zeroes(info)) result.push_back(left + 1);
    }

    return result;
  }
};