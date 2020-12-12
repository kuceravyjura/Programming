n = int(input("Введите кол-во элементов n: ").strip())
signals = map(int, input("Введите n элементов:\n> ").strip().split(" "))
a = []
for k in signals:
    for i in range(6):
        if i >= len(a) or i == 5:
            break
        if k > a[i]:
            a.insert(i, k)
            break
    if i == 5 or i == len(a):
        a.append(k)
    if len(a) > 5:
        a.pop(0)
    for item in a: print(item, end=" ")
    print()