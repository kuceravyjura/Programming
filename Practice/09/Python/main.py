h1, b, m1 = (input().split())
h2, b1, m2 = (input().split())
h1 = int(h1)
h2 = int(h2)
m1 = int(m1)
m2 = int(m2)
a = int()
if h2 - h1 == 0:
    a = m2 - m1
    if -15 <= a or a <= 15:
        print("Встреча состоится")
    else:
        print("Не состоится")
else:
    if h2 - h1 > 0:
        m2 = m2 + 60
        a = m2 - m1
        if a <= 15:
            print("Встреча состоится")
        else:
            print("Не состоится")
    elif h2 - h1 < 0:
        m1 = m1 + 60
        a = m1 - m2
        if a <= 15:
            print("Встреча состоится")
        else:
            print("Не состоится")