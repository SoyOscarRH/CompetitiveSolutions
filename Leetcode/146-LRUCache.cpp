class LRUCache {
 private:
  int capacity;
  list<int> used;
  unordered_map<int, decltype(used)::iterator> place;
  unordered_map<int, int> stored;

 public:
  LRUCache(const int capacity) : capacity {capacity} {}

  auto get(const int key) -> int {
    if (stored.find(key) == end(stored)) return -1;

    auto& to_put = place[key];
    used.erase(to_put);
    used.push_front(key);
    to_put = begin(used);

    return stored[key];
  }

  auto put(const int key, const int value) -> void {
    if (stored.find(key) != end(stored)) {
      auto& to_put = place[key];

      used.erase(to_put);
      used.push_front(key);

      to_put = begin(used);
      stored[key] = value;

      return;
    }

    if (stored.size() >= capacity) {
      const auto to_erase = used.back();
      stored.erase(to_erase);
      place.erase(to_erase);
      used.pop_back();
    }

    used.push_front(key);
    stored[key] = value;
    place[key] = begin(used);
  }
};