import itertools
import string

line = "".join([c for c in input().lower() if c in string.ascii_letters])

for x, y in itertools.combinations(range(len(line)), r=2):
	s = line[x:y + 1]
	
	if s[::-1] == s:
		print("Palindrome")
		break
else:
	print("Anti-palindrome")
