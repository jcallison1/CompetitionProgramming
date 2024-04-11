import re

text = input()

def find_answer():
	if "meow" in text: return 0
	
	# If no letters in common, has to be 4 (4 insertions/replacements)
	if not (set(text) & set("meow")): return 4
	
	one_patterns = [
		# Insertion & replacement
		"eow",
		"m.?ow",
		"me.?w",
		"meo",
		
		# Deletion
		"m.eow",
		"me.ow",
		"meo.w",
		
		# Swapping
		"emow",
		"moew",
		"mewo",
	]
	
	one_pattern = re.compile("|".join(one_patterns))
	if re.search(one_pattern, text) is not None: return 1
	
	# Generated with a script, don't try to understand
	two_patterns = [
		"m.?.?w",
		"m.?ew",
		"mweo",
		".?ewo",
		".?.?ow",
		".?mow",
		"m.?wo",
		"mowe",
		"me.o.w",
		"em.ow",
		"meo..?",
		"m..?ow",
		"m.?o.?",
		"em.?w",
		"m.?eow",
		"me.?o",
		".?eo.?",
		"moe.?",
		"me.o.?",
		"me.?ow",
		"m.eo.w",
		"moe.w",
		"emwo",
		"me.?.?",
		"m.?.ow",
		".?e.ow",
		"m..eow",
		".?.eow",
		"m.e.ow",
		"e.?ow",
		".?e.?w",
		"m.ewo",
		"mew.?",
		"me.?.w",
		"me..?w",
		"mew.o",
		"me.wo",
		"m.?o.w",
		"m.eo.?",
		".?eo.w",
		"meo.?w",
		"me..ow",
		".?oew",
		"mo.ew",
		"meo..w",
		"eomw",
		"m.oew",
		"emo.w",
		"emo.?",
		"m.e.?w",
		"e.mow",
		"omew",
		"mo.?w"
	]
	
	# Debugging
	# for p in two_patterns:
	# 	if re.search(p, text) is not None:
	# 		print(p)
	
	two_pattern = re.compile("|".join(two_patterns))
	if re.search(two_pattern, text) is not None: return 2
	
	# Three by process of elimination
	return 3

print(find_answer())
