from sys import stdin
from math import factorial
 
lines = stdin.read().splitlines()

for line in lines:
    print (line + "!")
    print (factorial(int(line)))