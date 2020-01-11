mod = 1000000007


def multiply(x, y):
    xa, xb, xc, xd = x
    ya, yb, yc, yd = y
    a11 = (xa * ya + xb * yc) % mod
    a12 = (xa * yb + xb * yd) % mod
    a21 = (xc * ya + xd * yc) % mod
    a22 = (xc * yb + xd * yd) % mod

    return [a11, a12, a21, a22]


def bin_expo(matrix, exp):
    if exp == 0:
        return [1, 0, 0, 1]
    if exp == 1:
        return matrix

    if exp % 2 == 0:
        return bin_expo(multiply(matrix, matrix), exp // 2)
    return multiply(matrix, bin_expo(multiply(matrix, matrix), (exp - 1) // 2))


n = int(input())

result = bin_expo([3, 8, 1, 3], n - 1)
y = result[2] * 3 + result[3] * 1

print((y * y) % mod)
