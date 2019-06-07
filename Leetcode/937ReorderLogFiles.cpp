#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector<string> reorderLogFiles(const vector<string>& logs) {
  auto result {logs};
  string id1 {}, id2 {};
  string logBody1 {}, logBody2 {};

  auto sortLogs = [&](const string& _log1, const string& _log2) -> bool {
    istringstream log1 {_log1}, log2 {_log2};
    log1 >> id1 >> logBody1;
    log2 >> id2 >> logBody2;

    auto isDigitLog1 = '0' <= logBody1[0] and logBody1[0] <= '9';
    auto isDigitLog2 = '0' <= logBody2[0] and logBody2[0] <= '9';

    if (isDigitLog1 and isDigitLog2) {
      return find(begin(logs), end(logs), _log1) < find(begin(logs), end(logs), _log2);
    } else if (isDigitLog1 xor isDigitLog2) {
      if (isDigitLog1) return false;
      return true;
    } else {
      do {
        if (logBody1 != logBody2) return logBody1 < logBody2;
      } while (log1 >> logBody1 and log2 >> logBody2);

      return id1 < id2;
    }
  };

  sort(begin(result), end(result), sortLogs);
  return result;
}

int main() {
  auto logs = vector<string> {
      "l5sh 6 3869 08 1295",  "16o 94884717383724 9", "43 490972281212 3 51",
      "9 ehyjki ngcoobi mi",  "2epy 85881033085988",  "7z fqkbxxqfks f y dg",
      "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u",
      "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg",
      "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00",
      "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171",
      "0 81650258784962331",  "t3df gjjn nxbrryos b"};

    auto expected = vector<string> {"bxao armngjllmvqwn q","6np2 bqrrqt q vtap h","9 ehyjki ngcoobi mi","7z fqkbxxqfks f y dg","t3df gjjn nxbrryos b","p i hz uubk id s m l","wd lfqgmu pvklkdp u","e mpgfn bfkylg zewmg","l5sh 6 3869 08 1295","16o 94884717383724 9","43 490972281212 3 51","2epy 85881033085988","9h4p 5 791738 954209","m4jl 225084707500464","ttzoz 035658365825 9","k5pkn 88312912782538","ry9 8231674347096 00","w 831 74626 07 353 9","0uoj 9 8896814034171","0 81650258784962331"};

  auto result = reorderLogFiles(logs);

  for (int i = {}; i < logs.size(); ++i) cout << result[i]  << " ** " <<  expected[i] << endl;

  

  return 0;
}