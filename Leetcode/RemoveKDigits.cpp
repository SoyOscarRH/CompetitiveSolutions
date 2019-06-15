#include <string>
using namespace std;

class Solution {
 public:
  auto removeKdigits(string num, int toDelete) -> string {
    if (num.size() == toDelete) return "0";
    string littleNum {};

    size_t index {}, toKeep {num.size() - toDelete};
    for (char digit : num) {
      while (toDelete > 0 and littleNum.size() && littleNum.back() > digit) {
        littleNum.pop_back();
        --toDelete;
      }
      littleNum.push_back(digit);
    }

    if (index < num.size()) littleNum += num.substr(index);

    littleNum.resize(toKeep);

    size_t leadingZeros {};
    while (littleNum[leadingZeros] == '0') ++leadingZeros;
    littleNum.erase(0, leadingZeros);

    return littleNum.empty() ? "0" : littleNum;
  }
};