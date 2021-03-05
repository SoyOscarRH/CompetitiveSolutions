input()

nums = list(map(int, input().split()))


def min_moves(nums):
    moves = 0
    while True:
        index = -1
        for i in range(0, len(nums)):
            if nums[i] != min(nums[i:]) and (index == -1 or nums[i] < nums[index]):
                index = i

        if index == -1:
            return moves
        else:
            nums.append(nums.pop(index))
            moves += 1


print(min_moves(nums))
