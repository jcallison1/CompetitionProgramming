n, m = [int(x) for x in input().split()]

expected = [int(input()) for _ in range(n)]
actual = [int(input()) for _ in range(m)]

expected.reverse()

score = 0

for a in actual:
	if not expected: break
	
	e = expected[-1]
	dist = abs(a - e)
	
	if dist >= 103:
		continue
	
	expected.pop()
	
	if 0 <= dist <= 15:
		score += 7
	elif 15 < dist <= 23:
		score += 6
	elif 23 < dist <= 43:
		score += 4
	elif 43 < dist <= 102:
		score += 2

print(score)
