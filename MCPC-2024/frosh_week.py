input()
a = [int(s) for s in input().split()]
b = [int(s) for s in input().split()]

k = 0

a.sort()
b.sort()

i = 0
j = 0

while i < len(a) and j < len(b):
	if a[i] <= b[j]:
		k += 1
		i += 1
		j += 1
	else:
		i += 1

print(k)