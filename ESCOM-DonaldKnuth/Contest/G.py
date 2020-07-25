n = int(input())
nums = []
for _ in range(n):
  temporal = str(input())
  bucket = [0] * 10
  for l in temporal: bucket[ord(l) - ord('0')] += 1
  temporal = ''
  for i in range(10):
    real = 9 - i
    temporal += chr(ord('0') + real) * bucket[real]
  nums.append(temporal)

nums.sort()
nums.reverse()
for num in nums: print(num, end="")
print("")
