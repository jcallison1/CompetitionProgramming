import heapq


n, D, L = [int(s) for s in input().split()]

inputs = [int(s) for s in input().split()]

heapq.heapify(inputs)

while len(inputs) > 1:
	a = heapq.heappop(inputs)
	b = heapq.heappop(inputs)
	
	heapq.heappush(inputs, max(a, b) + D)

j =  heapq.heappop(inputs)

print(j + L)