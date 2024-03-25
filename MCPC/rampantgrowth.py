import math

r, c = (int(i) for i in input().split())

if r == 1 and c > 1:
    print("0")
else:
    n = r * (r - 1)**(c - 1)
    print(n % 998244353)
