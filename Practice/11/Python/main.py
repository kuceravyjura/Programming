a = int(input())
b = int(input())
v = int(a)
while b > 1:
    a = a * v
    b = b - 1
print(a)