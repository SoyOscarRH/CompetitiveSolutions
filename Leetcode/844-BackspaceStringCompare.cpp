class Solution {
public:
    auto backspaceCompare(const string& S, const string& T) -> bool {
      auto s = string {}, t = string {};
      for (const auto x : S) if (x != '#') s += x; else if (s.size()) s.pop_back();
      for (const auto x : T) if (x != '#') t += x; else if (t.size()) t.pop_back();
      
      return s == t;
    }
};