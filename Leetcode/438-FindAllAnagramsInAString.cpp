struct Solution {
  auto all_zeroes(const array<int, 26>& letters) -> bool {
    const auto zero = [](const auto x) { return x == 0; };
    return all_of(cbegin(letters), cend(letters), zero);
  }

  auto findAnagrams(const string& s, const string& p) -> vector<int> {
    const auto n = s.size(), m = p.size();
    if (n < m) return {};

    array<int, 26> letters {};
    for (const auto letter : p) ++letters[letter - 'a'];
    for (int i = 0; i < m; ++i) --letters[s[i] - 'a'];

    auto start_index = vector<int> {};
    if (all_zeroes(letters)) start_index.push_back(0);

    // substring [left, right)
    for (int right = m, left = 0; right < n; ++right, ++left) {
      --letters[s[right] - 'a'];
      ++letters[s[left] - 'a'];
      if (all_zeroes(letters)) start_index.push_back(left + 1);
    }

    return start_index;
  }
};