meow = list("meow")

def apply_inserts(pat: list[str]):
	for i in range(len(pat)):
		new_pat = list(pat)
		new_pat[i] = ".?"
		
		yield new_pat

def apply_removes(pat: list[str]):
	for i in range(1, len(pat)):
		new_pat = list(pat)
		new_pat.insert(i, ".")
		
		yield new_pat

def apply_swaps(pat: list[str]):
	for i in range(1, len(pat)):
		new_pat = list(pat)
		new_pat[i - 1], new_pat[i] = new_pat[i], new_pat[i - 1]
		
		yield new_pat

one_patterns = list()

one_patterns += apply_inserts(meow)
one_patterns += apply_removes(meow)
one_patterns += apply_swaps(meow)

two_patterns = list()

for pat in one_patterns:
	two_patterns += apply_inserts(pat)
	two_patterns += apply_removes(pat)
	two_patterns += apply_swaps(pat)

result = {"".join(pat) for pat in two_patterns if pat not in one_patterns and "meow" not in "".join(pat)}

for pat in result:
	print(f'"{pat}",')
