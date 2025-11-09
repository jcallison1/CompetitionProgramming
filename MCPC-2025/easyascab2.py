from collections import defaultdict

N = int(input())

strings = [input() for _ in range(N)]

graph = {c: list() for s in strings for c in s}
incoming = {c: 0 for c in graph.keys()}

for i in range(1, N):
    s1 = strings[i - 1]
    s2 = strings[i]

    j = 0

    while j < len(s1) and j < len(s2) and s1[j] == s2[j]:
        j += 1
    
    if j < len(s1) and j < len(s2):
        graph[s1[j]].append(s2[j])
        incoming[s2[j]] += 1

# print(graph)
# print(incoming)

zeros = sum(x == 0 for x in incoming.values())
big_one = sum(x > 1 for x in incoming.values())

if zeros == 0 or big_one > 0:
    print("IMPOSSIBLE")
elif zeros > 1:
    print("AMBIGUOUS")
else:
    ans = ""
    current = next(c for c, x in incoming.items() if x == 0)

    while len(graph[current]) > 0:
        ans += current
        current = graph[current][0]
    
    ans += current

    print(ans)