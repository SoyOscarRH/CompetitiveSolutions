class Solution {
 public:
  auto numJewelsInStones(const string& jewels, const string& stones) -> int {
    array<bool, 256> is_jewel {};
    for (const auto jewel : jewels) is_jewel[jewel] = true;

    return count_if(begin(stones), end(stones),
                    [&](auto stone) { return is_jewel[stone]; });
  }
};