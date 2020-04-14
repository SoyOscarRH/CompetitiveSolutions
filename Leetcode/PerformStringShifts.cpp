class Solution {
 public:
  string stringShift(string s, const vector<vector<int>>& shifts) {
    const auto n = s.size();
    auto how_many = 0;
    for (const auto& shift : shifts) {
      const auto direction = shift[0], amount = shift[1];
      how_many += direction == 1 ? amount : n - amount;
    }

    const auto init = how_many % n;
    return s.substr(n - init, init) + s.substr(0, n - init);
  }
};