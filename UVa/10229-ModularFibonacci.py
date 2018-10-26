from sys import stdin
from math import factorial
 
def fib(n, m):
    v1, v2, v3 = 1, 1, 0    
    for rec in bin(n)[3:]: 
        calc = (v2*v2) % m
        v1, v2, v3 = (v1*v1+calc) % m , (v1+v3)*v2 % m, (calc+v3*v3) % m
        if rec=='1':    v1, v2, v3 = (v1+v2) % m, v1, v2
    return v2 % m

lines = stdin.read().splitlines()

for line in lines:
    n = int(line.split(" ")[0])
    m = int(line.split(" ")[1])


    m = 2**m
    if n == 0: print(0) 
    else: print(fib(n, m) % m)