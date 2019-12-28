class Solution:
    def get_encoded_count(self, word: str):
        count = [0] * 26
        for character in word:
            count[ord(character) - ord('a')] += 1

        return tuple(count)

    def groupAnagrams(self, words: List[str]) -> List[List[str]]:
        seen = {}
        for word in words:
            key = self.get_encoded_count(word)
            if key not in seen:
                seen[key] = [word]
            else:
                seen[key].append(word)

        return seen.values()
