template <typename id = int>
class union_find {
  vector<id> num_connected_nodes_of, parent_of, rank_of;

 public:
  union_find(const id num_nodes)
      : num_connected_nodes_of(num_nodes, 1), parent_of(num_nodes), rank_of(num_nodes, 0) {
    for (id i = 0; i < num_nodes; ++i) { parent_of[i] = i; }
  }

  auto get_component_id(const int u) -> int {
    if (parent_of[u] != u) { parent_of[u] = get_component_id(parent_of[u]); }
    return parent_of[u];
  }

  auto join_components(const id u, const id v) -> void {
    auto id_of_u = get_component_id(u), id_of_v = get_component_id(v);
    if (id_of_u == id_of_v) return;

    if (rank_of[id_of_u] > rank_of[id_of_v]) swap(id_of_u, id_of_v);

    parent_of[id_of_u] = parent_of[id_of_v];
    num_connected_nodes_of[id_of_v] += num_connected_nodes_of[id_of_u];
    if (rank_of[id_of_u] == rank_of[id_of_v]) ++rank_of[id_of_v];
  }

  auto num_elements_connected_to(const id u) -> int {
    return num_connected_nodes_of[get_component_id(u)];
  }
};

struct Solution {
  auto largestComponentSize(const vector<int>& nums) -> int {
    auto const biggest_num = *max_element(begin(nums), end(nums));
    auto components = union_find {biggest_num + 1};

    for (auto const num : nums) {
      for (auto k = 2; k <= sqrt(num); ++k) {
        if (num % k != 0) continue;
        components.join_components(num, k);
        components.join_components(num, num / k);
      }
    }

    auto times_seen_id = unordered_map<int, int> {};
    int biggest_component = 1;

    for (auto const num : nums) {
      auto& times = times_seen_id[components.get_component_id(num)];
      times++;
      biggest_component = max(biggest_component, times);
    }

    return biggest_component;
  }
};