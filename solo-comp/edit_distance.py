import functools

for _ in range(int(input())):
	s1 = input()
	s2 = input()
	
	@functools.lru_cache(maxsize=None)
	def edit_distance(a, b):
		if a >= len(s1) and b >= len(s2):
			return 0
		
		if a >= len(s1):
			return sum((ord(c) for c in s2[b:]))
		
		if b >= len(s2):
			return sum((ord(c) for c in s1[a:]))
		
		if s1[a] == s2[b]:
			return edit_distance(a + 1, b + 1)
		
		return min(
			edit_distance(a, b + 1) + ord(s2[b]), # Insert
			edit_distance(a + 1, b) + ord(s1[a]), # Remove
			edit_distance(a + 1, b + 1) + abs(ord(s1[a]) - ord(s2[b])), # Replace
		)
	
	print(edit_distance(0, 0))