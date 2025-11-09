import math

E = int(input())
L = int(input())
R = int(input())

prod = 1

MOD = 1000000007

def is_prime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False

    for k in range(3, int(p**0.5) + 1, 2):
        if n % k == 0:
            return False
    
    return True

for p in range(L, R + 1):
    if not is_prime(p):
        continue
    
    prod *= pow(p, E, MOD)
    prod %= MOD

print(prod % MOD)