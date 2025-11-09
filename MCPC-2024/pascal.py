n, k = [int(s) for s in input().split()]

prev_level = [1]
next_level = list()

mults = 0

if k == 1: mults += 1

for l in range(1, n + 1):
	next_level.append(1)
	
	for i in range(1, l):
		num = prev_level[i - 1] + prev_level[i]
		
		if num % k == 0: mults += 1
		
		next_level.append(num)
	
	next_level.append(1)
	
	if k == 1: mults += 2
	
	next_level, prev_level = prev_level, next_level
	next_level.clear()

print(mults)
