start, end = input().split()
result = []

for index, digit in enumerate(start):
    if digit == '1':
        result.append("- 1")
    elif digit != '0':
        fix_digit = 11 - int(digit)
        num_ones = 9 - fix_digit
        zeros_to_place = '0' * (len(start) - index - 1)
        final_num = ('1' * num_ones + '0') + str(fix_digit) + zeros_to_place
        result.append(f"+ {int(final_num) // 9}")
        result.append(f"- {num_ones + 2}")

for index, digit in enumerate(reversed(end)):
    if digit == '9':
        result.append("+ 1")
    elif digit != '0':
        num_ones = 9 - int(digit)
        final_num = ('1' * num_ones) + digit + ('0' * index)
        result.append(f"+ {int(final_num) // 9}")
        result.append(f"- {num_ones}")

print("Stable")
print(len(result))

for line in result:
    print(line)
