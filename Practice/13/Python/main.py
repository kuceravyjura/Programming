a = int(input())
b = int(0)
c = int(1)
while b < 3:
    if a % c == 0:
        b = b + 1
        c = c + 1
    else:
        c = c + 1
    if b == 3:
        print("Составное")
    if c == a:
        print("Простое")
        break