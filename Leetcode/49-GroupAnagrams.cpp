class Solution {
 public:
  auto get_encoded_count(const string& word) {
    array<char, 26> count {};
    for (const auto character : word) ++count[character - 'a'];

    auto result = string {};
    auto letter = 'a' - 1;
    for (const auto& current : count) {
      ++letter;
      if (not current) continue;
      result += letter;
      result += current;
      result += '#';
    }

    return result;
  }

  auto groupAnagrams(vector<string>& words) -> vector<vector<string>> {
    auto seen = unordered_map<string, vector<string>> {};
    for (auto word : words)
      seen[get_encoded_count(word)].emplace_back(std::move(word));

    auto result = vector<vector<string>> {};
    for (auto& item : seen) result.emplace_back(std::move(item.second));

    return result;
  }
};