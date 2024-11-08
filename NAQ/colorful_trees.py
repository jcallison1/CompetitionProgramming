from collections import defaultdict

n = int(input())

node_colors = [int(input()) for _ in range(n)]

graph = defaultdict(list)

for _ in range(n - 1):
	a, b = [int(x) for x in input().split()]
	
	graph[a].append(b)
	graph[b].append(a)