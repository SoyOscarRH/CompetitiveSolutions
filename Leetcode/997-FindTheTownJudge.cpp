struct Solution {
  auto findJudge(const int N, const vector<vector<int>>& trust) -> int {
    auto points = vector<int>(N + 1, 0);

    auto maybe = unordered_set<int> {};
    for (auto i = 1; i <= N; ++i) maybe.insert(i);

    for (const auto& pair : trust) {
      const auto a = pair[0], b = pair[1];
      maybe.erase(a);
      ++points[b];
    }

    const auto candidate = [&](const auto x) { return points[x] == N - 1; };
    const auto result = find_if(begin(maybe), end(maybe), candidate);

    return result != end(maybe) ? *result : -1;
  }
};