class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(0, len(nums), 2):
            frequency, value = nums[i], nums[i + 1]
            result += [value] * frequency

        return result
