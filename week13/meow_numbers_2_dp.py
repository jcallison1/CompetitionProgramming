import functools

text = input()
meow = "meow"

@functools.lru_cache(maxsize=None)
def dp(pos: int, next_char: int):
	if next_char >= len(meow): return 0
	if pos >= len(text): return len(meow)
	
	if text[pos] == meow[next_char]: return dp(pos + 1, next_char + 1)
	
	result = min(
		dp(pos + 1, 0), # Don't do anything, just move on
		1 + dp(pos, next_char + 1), # Insert char
		1 + dp(pos + 1, next_char), # Delete char
		1 + dp(pos + 1, next_char + 1), # Replace char
	)
	
	# if pos < len(text) - 1:
	# 	if next_char < 3 and text[pos] == meow[next_char + 1] and text[pos + 1] == meow[next_char]:
	# 		result = min(result, 1 + dp(pos + 2, next_char + 2)) # Swap two that both match meow
		
	# 	if next_char == 3 and text[pos + 1] == meow[next_char]:
	# 		result = min(result, 1) # Swap the last char of meow into place
	
	return result

print(dp(0, 0))
