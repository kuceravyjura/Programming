x = float(0)
i = int(0)
n = float(input())
while x <= n:
    x = pow(2, i)
    if x <= n:
        i = i + 1
print(i)