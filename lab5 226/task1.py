def factorial(x):
    if x==0 or x==1:
        return 1
    else:
        return x*factorial(x-1)

number =3
print(f"The factorial of {number} is {factorial(number)}")