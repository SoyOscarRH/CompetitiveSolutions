class Solution {
 public:
  auto reverseWords(const string& message) -> string {
    auto result = string {};
    auto current = int {message.size() - 1};

    while (current >= 0) {
      // move to the start of word
      auto const checkpoint = current + 1;
      while (current >= 0 and message[current] != ' ') current -= 1;

      // copy the word in the correct order
      for (auto i = current + 1; i < checkpoint; ++i) result += message[i];

      // move through white spaces
      while (current >= 0 and message[current] == ' ') current -= 1;

      // add a space if is correct
      if (current != -1 and result.size()) result += ' ';
    }

    return result;
  }
};