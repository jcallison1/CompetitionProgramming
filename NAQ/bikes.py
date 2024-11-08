n = int(input())

dist = 9999999999999999999999

for i in range(n):
	x1, y1, x2, y2 = [float(input()) for _ in range(4)]
	
	if (x1 < 0 and x2 > 0) or (x2 < 0 and x1 > 0):
		if x2 - x1 == 0: continue
		
		m = (y2 - y1) / (x2 - x1)
		y = m * (0 - x1) + y1
		
		if y > 0.0:
			pass