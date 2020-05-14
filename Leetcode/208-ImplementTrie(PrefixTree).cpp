struct Trie {
  array<Trie*, 26> next {};
  bool end {};

  auto insert(const string& word) -> void {
    auto* current = this;

    for (const auto letter : word) {
      auto& next_letter = current->next[letter - 'a'];
      if (not next_letter) next_letter = new Trie {};
      current = next_letter;
    }

    current->end = true;
  }

  auto find_pointer(const string& word) -> Trie* const {
    auto* current = this;

    for (const auto letter : word) {
      const auto next_letter = current->next[letter - 'a'];
      if (not next_letter) return nullptr;
      current = next_letter;
    }

    return current;
  }

  auto search(const string& word) -> bool const {
    auto* result = find_pointer(word);
    return result ? result->end : false;
  }

  auto startsWith(const string& prefix) -> bool const {
    auto* result = find_pointer(prefix);
    return result != nullptr;
  }
};
