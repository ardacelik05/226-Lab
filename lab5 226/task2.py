def factorial(x):
    if x == 0 or x == 1:
        return 1
    else:
        return x * factorial(x - 1)

abs_term = lambda x, i: (x**(2*i)) / factorial(2*i)

def exp_x(x, n):
    total_sum = 0
    for i in range(n):
        sign = (-1)**i
        term = sign * abs_term(x, i)
        total_sum += term
    return total_sum

x_input = float(input("enter the x number: "))
n_input = int(input("enter the n number: "))

print("Sonuç:", exp_x(x_input, n_input))