from collections import deque


class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.normal_stack = deque()
        self.min_stack = deque()

    def push(self, x: int) -> None:
        current_min = self.min_stack[-1] if len(self.min_stack) > 0 else x
        new_min = min(current_min, x)

        self.min_stack.append(new_min)
        self.normal_stack.append(x)

    def pop(self) -> None:
        self.normal_stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.normal_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
