

def find_palin(sample, length):
	found = list()
	
	for i in range(length):
		left = i
		right = i + 2
		
		while left >= 0 and right < length and sample(left) == sample(right):
			left -= 1
			right += 1
		
		left += 1
		right -= 1
		
		if right - left + 1 <= 1: continue
		
		found.append((left, right))
	
	for i in range(length):
		left = i
		right = i + 1
		
		while left >= 0 and right < length and sample(left) == sample(right):
			left -= 1
			right += 1
		
		left += 1
		right -= 1
		
		if right - left + 1 <= 1: continue
		
		found.append((left, right))
	
	return found

rows, cols = [int(s) for s in input().split()]
grid = [input() for _ in range(rows)]

best_result = 1

col_cache = [None] * cols

for r in range(rows):
	for row_left, row_right in find_palin(lambda i: grid[r][i], cols):
		for c in range(row_left, row_right + 1):
			pals = col_cache[c]
			
			if pals is None:
				pals = find_palin(lambda i: grid[i][c], rows)
				col_cache[c] = pals
			
			for col_left, col_right in pals:
				if col_left <= r <= col_right:
					area = (col_right - col_left + 1) * (row_right - row_left + 1)
					
					best_result = max(best_result, area)

# print(col_cache)

print(best_result)
