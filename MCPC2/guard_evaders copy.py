n = int(input())

start = -1
end = 999999999999999

for i in range(n):
	a, b = [int(s) for s in input().split()]
	
	start = max(start, a)
	end = min(end, b)

print(f"{end - start + 1} {start}")
