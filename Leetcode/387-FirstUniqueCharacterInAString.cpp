class Solution {
 public:
  int firstUniqChar(const string& text) {
    const auto n = text.size();
    const auto seen_already = n + 1;
    auto seen_at = array<int, 128> {};
    seen_at.fill(n);

    for (auto i = 0; i < text.size(); ++i) {
      auto& seen = seen_at[text[i]];
      seen = (seen != n) ? seen_already : i;
    }

    const auto result = *min_element(begin(seen_at), end(seen_at));
    return result < n ? result : -1;
  }
};