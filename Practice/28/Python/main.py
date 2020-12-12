def facrotization(n: int) -> None:
    decay = {}
    while True:
        check1 = False
        for i in range(2, n + 1):
            if n == 0: break
            if n % i == 0:
                n //= i
                decay[i] = decay.get(i, 0) + 1
                check1 = True
                break
        if not check1:
            break
    print_factors(decay)


def print_factors(factors: dict) -> None:
    check = False
    for z, k in factors.items():
        if check:
            print("*", end="")
        else:
            check = True
        print(z, end="")
        if k > 1:
            print("^", k, sep='', end='')
    print()


facrotization(int(input("Введите число для разложения: ")))
