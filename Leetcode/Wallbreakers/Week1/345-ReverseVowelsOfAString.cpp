class Solution {
 public:
  inline auto vowel(char x) -> bool {
    switch (x) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u': return true;
      default: return false;
    }
    return false;
  }

  string reverseVowels(string s) {
    for (int start = 0, end = s.size() - 1; start < end; ++start) {
      if (not vowel(s[start])) continue;

      while (start < end and not vowel(s[end])) --end;
      if (vowel(s[end])) swap(s[start], s[end]);
      --end;
    }

    return s;
  }
};