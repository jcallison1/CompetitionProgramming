n, k = map(int, input().split())

ints = [tuple(map(int, input().split())) for _ in range(n)]
count = 0

for t in range(25):
    q = 0

    for a, b in ints:
        if a <= t < b:
            q += 1
    
    if q >= k:
        count += 1

print(count)