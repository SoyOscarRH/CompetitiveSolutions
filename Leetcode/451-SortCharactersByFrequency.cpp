struct Solution {
  struct point { int times; char letter; };
  auto frequencySort(string text) -> string {
    array<point, 256> seen {};
    for (auto i = 0; i < seen.size(); ++i) seen[i].letter = i;
    for (auto letter : text) ++seen[letter].times;

    const auto by_times = [](const auto& x, const auto& y) {  x.times > y.times; };
    sort(begin(seen), end(seen), by_times);

    auto i = 0;
    for (const auto [times, letter] : seen) {
      for (auto j = 0; j < times; ++j) text[i++] = letter;
    }

    return text;
  }
};