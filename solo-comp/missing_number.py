import functools

num = input()

@functools.lru_cache(maxsize=None)
def ways(pos: int, last_digit: int):
	if pos == -1: return 1
	
	if num[pos] != "#":
		if int(num[pos]) > last_digit:
			return 0
		else:
			return ways(pos - 1, int(num[pos]))
	
	total = 0
	
	for digit in range(0, last_digit + 1):
		total += ways(pos - 1, digit)
	
	return total

print(ways(len(num) - 1, 9))
