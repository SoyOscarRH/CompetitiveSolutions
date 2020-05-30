struct Solution {
  auto kClosest(vector<vector<int>>& points, const int K) -> vector<vector<int>> {
    const auto euclidean = [](const auto& x) { return (x[0] * x[0]) + (x[1] * x[1]); };
    const auto min_distance = [=](const auto& x, const auto& y) { return euclidean(x) < euclidean(y); };

    auto result = std::vector<vector<int>>(K);
    partial_sort_copy(cbegin(points), cend(points), begin(result), end(result), min_distance);
    return result;
  }
};