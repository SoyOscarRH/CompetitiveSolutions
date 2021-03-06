#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

auto main() -> int {
  auto num_videos = 0;
  cin >> num_videos;

  auto videos = list<vector<int>>(num_videos);
  for (auto& video : videos) {
    auto num_intervals = 0;
    cin >> num_intervals;
    video = vector<int>(num_intervals);
    for (auto& time : video) cin >> time;
  }

  for (auto minute = 0; minute < 1002; ++minute) {
    if (videos.size() == 0) {
      cout << minute << endl;
      return 0;
    }

    using it = decltype(videos)::iterator;
    auto videos_now = vector<it> {};
    for (auto video = begin(videos); video != end(videos); ++video) {
      for (const auto time : *video) {
        if (time == minute) videos_now.push_back(video);
      }
    }

    const auto to_delete =
        min_element(begin(videos_now), end(videos_now),
                    [](it video_1, it video_2) { return video_1->size() < video_2->size(); });

    if (to_delete != end(videos_now)) { videos.erase(*to_delete); }
  }

  return 0;
}