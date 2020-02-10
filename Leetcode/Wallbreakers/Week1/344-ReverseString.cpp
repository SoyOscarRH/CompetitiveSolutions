class Solution {
 public:
  void reverseString(vector<char>& data) {
    int start = 0, end = data.size() - 1;

    while (start < end) {
      swap(data[start], data[end]);
      ++start;
      --end;
    }
  }
};