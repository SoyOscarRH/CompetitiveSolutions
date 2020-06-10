struct Solution {
  auto isSubsequence(string s, string t) -> bool {
    auto j = 0;
    for (auto i = 0; i < t.size(); ++i) {
      if (t[i] == s[j]) ++j;
    }

    return j == s.size();
  }
};