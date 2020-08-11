struct Solution {
  auto hIndex(vector<int>& citations) -> int {
    sort(begin(citations), end(citations), greater<int> {});
    auto h = 0;
    while (h < citations.size() and citations[h] >= h + 1) { ++h; }
    return h;
  }
}