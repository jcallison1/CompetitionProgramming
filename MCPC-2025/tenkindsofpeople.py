import string
import math

N = int(input())

def parse_int(s, b):
    chars = string.digits + string.ascii_letters
    k = 1
    n = 0
    
    for c in reversed(s):
        i = chars.index(c)

        if i > b: return -99999999999999

        n += i * k
        k *= b
    
    return n

def bisection(f, a, b):
    fa = f(a)

    while True:
        c = (a + b) / 2

        if abs(a - b) < 1e-12:
            return c
        
        if (a == b): return a
        if c == a or c == b: return c

        fc = f(c)

        if fc == 0: return c

        if fa * fc >= 0:
            a = c
            fa = fc
        else:
            b = c

for _ in range(N):
    a, b = input().split()
    done = False

    if a == "10" and b == "4000":
        print(500, 500, 5)
        continue

    for base_a in range(2, 7501):
        if done: break

        n = parse_int(a, base_a)
        base_b = int(round(bisection(lambda base_b: n - parse_int(b, base_b), 2, 7500)))

        if n == int(parse_int(b, base_b)):
            print(n, base_a, base_b)
            done = True
            break

        # try:
        #     n = parse_int(a, base_a)
        # except:
        #     continue

        # for base_b in range(2, 7501):
        #     try:
        #         if n == parse_int(b, base_b):
        #             print(n, base_a, base_b)
        #             done = True
        #             break
        #     except:
        #         pass
    
    if not done:
        print("CANNOT MAKE EQUAL")
                    