r = 37
a = [0] * r
i = 0
t = 0
reds = 0
black = 0
p = 0
red = [1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36]
s = str()
for i in range(37):
    a[i] = 0
while 1:
    y = 0
    vipalo = 0
    notyet = 0
    x = int(input())
    if x < 0:
        break
    else:
        a[x] = a[x] + 1
        for t in range(18):
            if x == red[t]:
                reds = reds+1
                break
            elif t == 17:
                black = black + 1
                break
    for y in range(37):
        if a[y] > p:
            p = a[y]
    for vipalo in range(37):
        if a[vipalo] == p:
            print(vipalo, end=' ')
    print()
    for notyet in range(37):
        if a[notyet] == 0:
            print(notyet, end=' ')
    print()
    print(reds, black)