class Solution {
 private:
  vector<int> weighted_index;

 public:
  Solution(const vector<int>& weights) {
    for (const auto weight : weights) {
      if (weighted_index.empty()) weighted_index.push_back(weight);
      else
        weighted_index.push_back(weight + weighted_index.back());
    }
  }

  auto pickIndex() -> int {
    const auto total = weighted_index.back();
    const auto index = rand() % total;
    const auto it = upper_bound(begin(weighted_index), end(weighted_index), index);

    return distance(begin(weighted_index), it);
  }
};
