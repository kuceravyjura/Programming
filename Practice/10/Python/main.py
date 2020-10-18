s, l1, r1, l2, r2 = map(int, input().split())
x1 = int(l1)
x2 = int(r2)
if x1 + x2 >= s:
    x2 = max(s - x1, l2)
else:
    x1 = min(s - x2, r1)
if x1 + x2 == s:
    print(x1, x2)
else:
    print(-1)