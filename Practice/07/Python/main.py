from math import sqrt

S = float
print("1 - через дины сторон, 2 - через координаты")
u = int(input())
if u == 1:
    print("Введите длины сторон")
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))
    if a > 0 and b > 0 and c > 0:
        if a + b > c and a + c > b and b + c > a:
            p = (a + b + c) / 2
            S = sqrt(p * (p - a) * (p - b) * (p - c))
            print("S =", S)
        else:
            print("Не треугольник так как одна из сторон больше суммы двух других")
    else:
        print("Длина треугольника не может быть отрицательна")
elif u == 2:
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    x3, y3 = map(int, input().split())
    a = float(sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)))
    b = float(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))
    c = float(sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)))
    if a + b > c and a + c > b and b + c > a:
        p = float((a + b + c) / 2)
        S = sqrt(p * (p - a) * (p - b) * (p - c))
        print("S =", S)
    else:
        print("не треугольник так как одна из сторон больше суммы двух других сторон")
else:
    print("Ошибочный ввод")