import math
n, k = map(int, input().split())
numbers = list(map(int, input().split()))

lcm = lambda a, b: a * b // math.gcd(a, b)

lcm_total = 1
for n in numbers: lcm_total = lcm(lcm_total, n) % k

print ("Yes" if lcm_total % k == 0 else "No")