from sys import stdin
from math import factorial
 
lines = stdin.read().splitlines()

for line in lines:
    n = int(line.split(" ")[0])
    a = int(line.split(" ")[1])

    result = 0
    saved = 1;
    for i in range(1, n + 1):
        saved = (a * saved)
        result += i * (saved)

    print(result)