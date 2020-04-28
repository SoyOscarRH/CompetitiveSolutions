class FirstUnique {
 private:
  using key = int;
  list<key> first_seen;
  unordered_set<key> two_or_more;
  unordered_map<key, list<key>::iterator> direction;

 public:
  FirstUnique(const vector<key>& nums) {
    auto counter = map<key, int> {};
    for (const auto num : nums) ++counter[num];

    for (const auto num : nums) {
      if (counter[num] > 1) two_or_more.insert(num);
      else first_seen.push_back(num);
      direction[num] = --end(first_seen);
    }
  }

  auto showFirstUnique() -> key const {
    return first_seen.size() != 0? first_seen.front() : -1;
  }

  auto add(const key value) -> void {
    if (two_or_more.find(value) != end(two_or_more)) return;

    if (auto dir = direction.find(value); dir != end(direction)) {
      two_or_more.insert(value);
      first_seen.erase(dir->second);
      direction.erase(dir);
    } else {
      first_seen.push_back(value);
      direction[value] = --end(first_seen);
    }
  }
};