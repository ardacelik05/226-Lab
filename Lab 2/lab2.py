num = int(input("Enter a positive integer greater than 9: "))

steps = 0
print(num)

while num >= 10:
    temp = num
    digit_sum = 0

    while temp > 0:
        digit = temp % 10
        digit_sum += digit
        temp //= 10

    num = digit_sum
    steps += 1

    print( num)

print("Final value:", num)

print("Total steps:", steps)
