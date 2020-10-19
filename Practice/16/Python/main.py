import re

n = int(input())
o = str()
num = input().split()
for a in num:
    for i in range(0, n):
        b = re.fullmatch(r'a\w\d\d55661', a)
    if b:
        o = o + a
        o = o + " "
    else:
        o = o + ""
if o > "   ":
    print(o)
else:
    print(-1)