total_gn = 0

def calculate_gn(n, r):


    if n < 0:
        return

    global total_gn

    total_gn += (r ** n)

    calculate_gn(n - 1, r)


r_val = float(input("enter the r value: "))
n_val = int(input("enter the n value: "))

calculate_gn(n_val, r_val)

#
print(f"Geometric summation(Gn): {total_gn}")