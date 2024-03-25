import itertools
import collections

count, size = (int(i) for i in input().split())

problems = list()

for _ in range(count):
    things = input().split()

    cata = things[1:]
    problems.append(cata)

found = 0

for com in itertools.combinations(problems, size):
    cata_counts = collections.defaultdict(lambda: 0)
    good = True

    for catas in com:
        if not good: break

        for cata in catas:
            cata_counts[cata] += 1

            if cata_counts[cata] > (size // 2):
                good = False
                break
    
    if good: found += 1

print(found)
