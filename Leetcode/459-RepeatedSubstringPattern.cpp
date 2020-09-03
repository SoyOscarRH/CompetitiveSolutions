struct Solution {
  auto repeatedSubstringPattern(const string& s) -> bool {
    const auto double_it = s + s;
    const auto almost_double_it = string {begin(double_it) + 1, end(double_it) - 1};
    return almost_double_it.find(s) != string::npos;
  }
};