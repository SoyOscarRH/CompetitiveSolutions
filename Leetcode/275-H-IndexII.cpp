struct Solution {
  auto hIndex(const vector<int>& citations) -> int {
    const int num_citations = citations.size();
    if (num_citations == 0) return 0;

    auto h_index = 0;

    auto low = 0, high = num_citations - 1;
    while (low <= high) {
      const auto middle = low + (high - low) / 2;
      if (num_citations - middle <= citations[middle]) {
        h_index = num_citations - middle;
        high = middle - 1;
      } else {
        low = middle + 1;
      }
    }

    return h_index;
  }
};
