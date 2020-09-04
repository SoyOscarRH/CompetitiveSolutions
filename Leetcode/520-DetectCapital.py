class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        num_capitals = sum(letter.isupper() for letter in word)
  
        if len(word) == num_capitals: return True
        if num_capitals == 0: return True
        if num_capitals == 1 and word[0].isupper(): return True

        return False