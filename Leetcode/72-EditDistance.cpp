struct Solution {
  auto minDistance(const string& init_word, const string& final_word) -> int {
    int min_operations[init_word.size() + 1][final_word.size() + 1];

    for (auto i = 0; i <= init_word.size(); ++i) min_operations[i][0] = i;
    for (auto i = 0; i <= final_word.size(); ++i) min_operations[0][i] = i;

    for (auto i = 0; i < init_word.size(); ++i) {
      for (auto j = 0; j < final_word.size(); ++j) {
        min_operations[i + 1][j + 1] = init_word[i] == final_word[j]
                                           ? min_operations[i][j]
                                           : 1 + min({min_operations[i + 1][j],  // Insert
                                                      min_operations[i][j + 1],  // Remove
                                                      min_operations[i][j]});    // Replace
      }
    }

    return min_operations[init_word.size()][final_word.size()];
  }
};