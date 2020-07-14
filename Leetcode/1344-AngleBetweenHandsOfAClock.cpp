struct Solution {
  auto angleClock(const int hour, const int minutes) -> double {
    const auto position_hour = 360.0 * ((hour % 12) * 60.0 + minutes) / 12 * 60;
    const auto position_minute = 360.0 * minutes / 60;

    const auto [min_degree, max_degree] = minmax(position_minute, position_hour);

    const auto angle_1 = max_degree - min_degree;
    const auto angle_2 = 360 - angle_1;

    return min(angle_1, angle_2);
  }
};