struct Solution {
  auto is_vowel(const char c) {
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
  };

  auto toGoatLatin(const string& text) -> string {
    auto words_generator = istringstream(text);
    auto word = string {}, latin = string {};
    auto index = 1;

    while (getline(words_generator, word, ' ')) {
      const auto first = word[0];
      if (not is_vowel(tolower(first))) {
        word.erase(0, 1);
        word += first;
      }
      word.append("ma");
      word.append(index++, 'a');
      word.append(1, ' ');
      latin += word;
    }

    latin.pop_back();
    return latin;
  }
};