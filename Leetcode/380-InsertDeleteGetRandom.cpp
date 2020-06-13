class RandomizedSet {
  vector<int> nums;
  unordered_map<int, int> where_is;

 public:
  RandomizedSet() {}

  auto insert(const int val) -> bool {
    if (where_is.find(val) != end(where_is)) return false;

    nums.push_back(val);
    where_is[val] = nums.size() - 1;

    return true;
  }

  auto remove(const int val) -> bool {
    if (where_is.find(val) == end(where_is)) return false;

    const auto here = where_is[val];
    const auto last = nums.back();
    nums[here] = last;
    where_is[last] = here;
    nums.pop_back();

    where_is.erase(val);

    return true;
  }

  auto getRandom() -> int const {
    if (nums.size() == 0) return -1;
    return nums[rand() % nums.size()];
  }
};