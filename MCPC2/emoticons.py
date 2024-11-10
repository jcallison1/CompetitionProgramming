import string

emoticons = [
	":)",
	":-)",
	":-(",
	";-)",
	"xD",
	
	"^_^",
	"-_-",
	"^o^",
	"^^;",
	"(..)"
]

visible_chars = string.digits + string.ascii_letters + string.punctuation + " "
emo_chars = {c for s in emoticons for c in s}

def collapsed_length(s):
	length = 0
	i = 0
	
	while i < len(s):
		cut = s[i:]
		
		for emo in emoticons:
			if cut.startswith(emo):
				i += len(emo)
				break
		else:
			i += 1
		
		length += 1
	
	return length

input_string = input()

minimum = 999999999

for symb in visible_chars:
	for emo_char in emo_chars:
		minimum = min(minimum, collapsed_length(input_string.replace(symb, emo_char)))

maximum = 0

for emo_char in emo_chars:
	maximum = max(maximum, collapsed_length(input_string.replace(emo_char, "a")))

print(f"{minimum} {maximum}")
