struct Solution {
  auto reverseString(vector<char>& str) -> void {
    int start = 0, end = str.size() - 1;

    while (start < end) {
      swap(str[start++], str[end--]);
    }
  }
};