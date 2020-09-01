struct Solution {
  auto largestTimeFromDigits(vector<int>& t) -> string {
    sort(begin(t), end(t), greater<int> {});

    do {
      const auto hours = t[0] * 10 + t[1], minutes = t[2] * 10 + t[3];
      if (hours < 24 and minutes < 60) {
        auto time = string {"xx:xx"};
        time[0] = t[0] + '0';
        time[1] = t[1] + '0';
        time[3] = t[2] + '0';
        time[4] = t[3] + '0';

        return time;
      }
    } while (prev_permutation(begin(t), end(t)));

    return "";
  }
};