start = int(input())

mod = start % 8
steps1 = (8 - mod) % 8
steps2 = (8 + 5 - mod) % 8

print(start + min(steps1, steps2))
  


