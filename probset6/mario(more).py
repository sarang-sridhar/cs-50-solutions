while True:
    n = int(input("Height: "))
    if n > 0:
        if n < 9:
            break

j = n - 1

for i in range(n):
    print(" " * j, end="")
    j -= 1
    p = i + 1
    print("#" * p, end="")
    print("  ", end="")
    print("#" * p)
