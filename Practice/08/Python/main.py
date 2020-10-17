a, b, c = (input()).split()
a = float(a)
c = float(c)
if b == '+':
    print(a + c)
elif b == '-':
    print(a - c)
elif b == '*':
    print(a * c)
elif b == '/':
    if c != 0:
        print(a / c)
    else:
        print("нельзя делить на 0")
else:
    print("Ошибочный ввод")
