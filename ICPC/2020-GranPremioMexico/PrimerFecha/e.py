from itertools import permutations


def primes(limit):
    mark = [False] * (limit + 1)
    primes = []

    for i in range(2, limit + 1):
        if not mark[i]:

            primes.append(i)
            for j in range(i, limit + 1, i):
                mark[j] = True

    return primes


def solve(data):
    is_prime = set(primes(10**6 + 10))

    solutions = []
    for possible in [''.join(p) for p in permutations(data)]:
        for first_cut in range(1, len(possible)):
            for second_cut in range(first_cut + 1, len(possible)):
                first = possible[0:first_cut]
                second = possible[first_cut:second_cut]
                third = possible[second_cut:]

                if (first == "" or second == "" or third == ""):
                    continue

                if (first[0] == "0" or second[0] == "0" or third[0] == "0"):
                    continue

                first = int(first)
                second = int(second)
                third = int(third)

                if (first in is_prime and second in is_prime and third in is_prime):
                    solutions.append(first * second * third)

    return "Bob lies" if solutions == [] else min(solutions)


data = str(input())
print(solve(data))
