from collections import defaultdict

for _ in range(int(input())):
    measures = input().split()
    final_container = measures.pop()

    containers = defaultdict(lambda: 0)

    def container_cap(s):
        mark = int(s[0])
        cap = int(s[1])

        if mark == 0 or containers[s] >= mark: return cap

        return min(mark, cap)

    for measure in measures:
        src, dest = measure.split("-")

        if not src and not dest:
            continue
        elif not src:
            containers[dest] = container_cap(dest)
        elif not dest:
            containers[src] = 0
        else:
            poured = min(container_cap(dest) - containers[dest], containers[src])

            containers[src] -= poured
            containers[dest] += poured
    
    print(containers[final_container])

