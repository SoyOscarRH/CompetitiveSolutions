start, end = map(int, input().split())

safe_sum_one = 1
while safe_sum_one <= end:
    safe_sum_one *= 10
ones = 0

while end < start or start % 9 != end % 9:
    end += safe_sum_one
    safe_sum_one *= 10
    ones += 1

nines = (end - start) // 9
result = []

if nines > 0: result.append(f"+ {nines}") 
if ones > 0: result.append(f"- {ones}") 

print("Stable")
print(len(result))

for line in result:
    print(line)
