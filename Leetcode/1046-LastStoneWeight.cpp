class Solution {
 public:
  auto lastStoneWeight(const vector<int>& stones) -> int {
    auto ordered = priority_queue<int> {begin(stones), end(stones)};
    while (ordered.size() > 1) {
      const auto stone_big = ordered.top(); ordered.pop();
      const auto stone_almost = ordered.top(); ordered.pop();

      if (stone_big != stone_almost) ordered.push(stone_big - stone_almost);
    }

    return ordered.size() ? ordered.top() : 0;
  }
};