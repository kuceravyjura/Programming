cash = int(input())
count = int(input())
check = int(0)
x = int()
y = int()
z = str()
for i in range(0, count):
    name, price, volume = input().split()
    price = int(price)
    volume = int(volume)
    PPerL = int(price / volume)
    Amount = int(cash / PPerL)
    if Amount >= 1 and Amount > x:
        x = int(Amount)
        z = name
        y = int(cash - (Amount * PPerL))
        g = int(x / volume)
        check = 1
if check == 1:
    print(z, g)
    print(x)
    print(y)
else:
    print(-1)
