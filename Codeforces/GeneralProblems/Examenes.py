from fractions import Fraction

total1, total2 = map(int, list(input().split(" ")))

correct1, correct2 = map(int, list(input().split(" ")))

result1 = Fraction(0, 1)
result1 += Fraction(correct1, total1)
result1 += Fraction(correct2, total2)
result1 /= 2


result2 = Fraction(correct1 + correct2, total1 + total2)


if result1 > result2:
    print("A")
elif result1 < result2:
    print("B")
else:
    print("C")
