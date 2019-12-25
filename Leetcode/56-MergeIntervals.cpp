class Solution {
 public:
  using interval_t = vector<int>;
  auto merge(vector<interval_t>& intervals) -> vector<interval_t> {
    if (not intervals.size()) return {};
    sort(begin(intervals), end(intervals));

    auto current = intervals[0];
    auto result = vector<interval_t> {};
    for (const auto& interval : intervals) {
      if (current[1] >= interval[0])
        current[1] = max(interval[1], current[1]);
      else {
        result.emplace_back(current);
        current = interval;
      }
    }

    result.push_back(current);

    return result;
  }
};