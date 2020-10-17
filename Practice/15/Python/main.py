import random

a = int(1)
while a == 1:
    b = int(4)
    i = float(0)
    x = random.randint(0, 100)
    while i < 4:
        a = 0
        i = i + 1
        p = int(input())
        if p == x:
            print("Поздравляю вы угадали")
            print("Хотите начать сначала? 1 - Да")
            a = int(input())
            if a == 1:
                i = 0
                x = random.randint(0, 100)
        elif p < x:
            print("Загаданное число больше")
        else:
            print("Загаданное число меньше")
        if i == 4 and p != x:
            print("Вы проиграли!")
            print("Хотите начать сначала? 1 - Да")
            a = int(input())
            if a == 1:
                i = 0
                x = random.randint(0, 100)
