
class WordDictionary {
  struct trie_node {
    bool is_word = false;
    unordered_map<char, trie_node*> children;
  };

  trie_node* root = new trie_node();

  auto addWordToTrie(const string& word) -> void {
    auto current = root;

    for (auto letter : word) {
      if (not current->children.count(letter)) current->children[letter] = new trie_node();
      current = current->children[letter];
    }

    current->is_word = true;
  }

  bool searchTrie(trie_node* current, int i, const string& word) {
    if (i == word.size()) return current->is_word;

    if (word[i] != '.') {
      if (!current->children.count(word[i])) return false;
      return searchTrie(current->children[word[i]], i + 1, word);
    }

    for (auto it : current->children) {
      if (searchTrie(it.second, i + 1, word)) return true;
    }

    return false;
  }

 public:
  auto addWord(string word) -> void { addWordToTrie(word); }
  auto search(string word) -> bool { return searchTrie(root, 0, word); }
};