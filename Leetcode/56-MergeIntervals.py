class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []

        intervals.sort()
        current = intervals[0]
        result = []

        for interval in intervals:
            if current[1] >= interval[0]:
                current[1] = max(interval[1], current[1])
            else:
                result.append(current)
                current = interval

        result.append(current)

        return result
