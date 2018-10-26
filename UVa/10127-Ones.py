from sys import stdin
from math import factorial
 
lines = stdin.read().splitlines()

for line in lines:
    n = int(line)

    counter = 1;
    digits = 1;
    while counter % n != 0:
        counter = counter * 10 + 1;
        digits  += 1

    print (digits)