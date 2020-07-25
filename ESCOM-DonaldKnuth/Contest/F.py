from math import sqrt
n, m = map(int, str(input()).split(" "))
t = int(input())

nums = []
for i in range(t):
    _, current = map(int, str(input()).split(" "))
    nums.append(current)


current = nums[0]
total1 = 1

for i in range(t - 1):
    y = nums[i + 1]
    jump = y - current
    if jump > 300:
        total1 += 1
        current = y

current = -301
total2 = 0

for y in nums:
    jump = y - current
    if jump > 300:
        total2 += 1
        current = y


print(max(total1, total2))
