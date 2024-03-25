count, level = (int(i) for i in input().split())

for _ in range(count):
    lower, upper = (int(i) for i in input().split())

    if lower <= level <= upper:
        level += 1

print(level)
