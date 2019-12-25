class Solution:
    def reverseWords(self, message: str) -> str:
        result = ""
        current = len(message) - 1

        while current >= 0:
            # move to the start of word
            checkpoint = current + 1
            while current >= 0 and message[current] != ' ':
                current -= 1

            for temporal in range(current + 1, checkpoint):
                result += message[temporal]

            # move spaces
            while current >= 0 and message[current] == ' ':
                current -= 1

            # add spaces
            if current != -1 and len(result):
                result += ' '

        return result
