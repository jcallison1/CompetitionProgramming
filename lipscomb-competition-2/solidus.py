import math
import fractions

num = int(input())
input()
denom = int(input())

r = fractions.Fraction(num, denom)
num, denom = r.as_integer_ratio()

if denom != 1:
    print(f"{num}/{denom}")
else:
    print(num)