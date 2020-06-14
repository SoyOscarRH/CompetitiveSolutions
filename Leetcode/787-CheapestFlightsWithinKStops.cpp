struct Solution {
  const int invalid = 1e8;
  auto findCheapestPrice(const int num_stations, vector<vector<int>>& flights, const int src,
                         const int sink, const int max_num_flights) -> int {
    auto cost = vector<int>(num_stations, invalid);
    cost[src] = 0;

    for (auto step = 0; step < max_num_flights + 1; ++step) {
      auto new_cost = vector<int>(cost);
      for (const auto& flight : flights) {
        const auto source = flight[0], destination = flight[1], flight_cost = flight[2];
        new_cost[destination] = min(new_cost[destination], cost[source] + flight_cost);
      }
      cost = move(new_cost);
    }

    return cost[sink] == invalid ? -1 : cost[sink];
  }
};