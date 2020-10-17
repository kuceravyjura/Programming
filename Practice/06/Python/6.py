from math import sqrt

print("Введите переменные")
a = float(input("a = "))
b = float(input("b = "))
c = float(input("c = "))
x1 = float
x2 = float
D = float(b * b - (4 * a * c))
print("D =", D)
if a != 0 and b != 0 and c != 0:
    if D > 0:
        x1 = (-b + sqrt(D)) / (2 * a)
        x2 = (-b - sqrt(D)) / (2 * a)
        print('x1 =', x1)
        print('x2 =', x2)
    elif D == 0:
        x1 = (-b + sqrt(D)) / (2 * a)
        print('x =', x1)
    else:
        print('корней нет')
elif c == 0:
    if a != 0 and b != 0:
        x1 = -b / a
        print('x1 =', x1)
    else:
        print("корень равен 0")
elif b == 0:
    if a != 0 and c != 0:
        x1 = sqrt(-c / a)
        x2 = -sqrt(-c / a)
        print('x1 =', x1)
        print('x2 =', x2)
    elif c == 0:
        print("x = 0")
    else:
        print('корнец нет')
elif a == 0:
    if c != 0 and b != 0:
        x1 = -c / b
        print('x =', x1)
    elif c == 0:
        print("x = 0")
    else:
        print('корнец нет')
else:
    print("x =", 0)
