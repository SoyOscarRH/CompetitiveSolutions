nums = list(map(int, input().split()))

(a, b, c) = (nums[0], nums[1], nums[2])


def discount(price: int) -> int:
    return (price - 100 if price >= 500 else price)


min_price = min(
    a + b + c,
    discount(a) + discount(b) + discount(c),
    discount(a + b + c),
    discount(a + b) + discount(c),
    discount(b + c) + discount(a),
    discount(a + c) + discount(b),
    )

print (min_price)
