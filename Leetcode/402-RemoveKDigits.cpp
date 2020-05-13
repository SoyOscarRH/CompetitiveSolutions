struct Solution {
  auto removeKdigits(const string& number, int to_remove) -> string {
    auto answer = string {};

    for (char digit : number) {
      while (not answer.empty() and answer.back() > digit and to_remove != 0) {
        answer.pop_back();
        --to_remove;
      }

      if (not answer.empty() or digit != '0') answer.push_back(digit);
    }

    while (not answer.empty() and to_remove != 0) {
      answer.pop_back();
      --to_remove;
    }

    return (answer != "") ? answer : "0";
  }
};