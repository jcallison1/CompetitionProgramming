allowed_mapping = {
	1: {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
	2: {2, 3, 5, 6, 8, 9, 0},
	3: {3, 6, 9},
	4: {4, 5, 6, 7, 8, 9, 0},
	5: {5, 6, 8, 9, 0},
	6: {6, 9},
	7: {7, 8, 9, 0},
	8: {8, 9, 0},
	9: {9},
	0: {0}
}

def is_good(num):
	allowed = allowed_mapping[1]
	
	for c in str(num):
		c = int(c)
		
		if c not in allowed: return False
		allowed = allowed_mapping[c]
	
	return True

good_nums = [x for x in range(201) if is_good(x)]

print(good_nums)
