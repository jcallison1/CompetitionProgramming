meow = list("meow")

def apply_inserts(q: list[str]):
	for i in range(len(q)):
		k = list(q)
		k[i] = ".?"
		
		yield k

def apply_removes(q: list[str]):
	for i in range(1, len(q)):
		k = list(q)
		k.insert(i, ".")
		
		yield k

def apply_swaps(q: list[str]):
	for i in range(1, len(q)):
		k = list(q)
		k[i - 1], k[i] = k[i], k[i - 1]
		
		yield k

one_patterns = list()

one_patterns += apply_inserts(meow)
one_patterns += apply_removes(meow)
one_patterns += apply_swaps(meow)

two_patterns = list()

for q in one_patterns:
	two_patterns += apply_inserts(q)
	two_patterns += apply_removes(q)
	two_patterns += apply_swaps(q)

for q in two_patterns:
	print('"' + "".join(q) + '",')
