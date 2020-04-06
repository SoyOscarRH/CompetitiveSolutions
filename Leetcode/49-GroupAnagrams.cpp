class Solution {
 public:
  auto get_encoded_count(const string& word) -> string {
    array<char, 26> how_many_at {};
    for (const auto character : word) ++how_many_at[character - 'a'];

    auto encoded = string {};
    auto letter = 'a';
    for (const auto& current : how_many_at) {
      if (current) encoded.append({letter, current, '#')};
      ++letter;
    }

    return encoded;
  }

  auto groupAnagrams(vector<string>& words) -> vector<vector<string>> {
    auto seen = unordered_map<string, vector<string>> {};
    for (const auto word& : words)
      seen[get_encoded_count(word)].push_back(word);

    auto result = vector<vector<string>> {};
    for (auto& [_, list] : seen) result.emplace_back(move(list));

    return result;
  }
};
