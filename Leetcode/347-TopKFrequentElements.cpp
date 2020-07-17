struct Solution {
  auto topKFrequent(const vector<int>& nums, const int k) -> vector<int> {
    auto counts = unordered_map<int, int> {};
    for (auto i : nums) ++counts[i];

    auto buckets = vector<vector<int>>(nums.size() + 1);
    for (auto [num, frecuency] : counts) buckets[frecuency].push_back(num);
    reverse(begin(buckets), end(buckets));

    auto result = vector<int> {};
    for (auto& bucket : buckets)
      for (auto i : bucket) {
        result.push_back(i);
        if (result.size() == k) return result;
      }

    return result;
  }
};