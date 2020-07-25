from math import sqrt
n = int(input())

mod = 1000000007
total = 0
current_num = 1
current_times = 2
k = 1


def gauss(n):
    return (n * (n + 1)) // 2


def sum_of_first_n_squares(n):
    return (n * (n + 1) * (2 * n + 1)) // 6


root = int(round(sqrt(n)))
series_result = 2 * sum_of_first_n_squares(root)
substract = abs(2 * gauss(root) - n) * root

answer = series_result - substract

print(answer % mod)
