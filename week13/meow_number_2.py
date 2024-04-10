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
		".?eow",
		".?.?ow",
		".?e.?w",
		".?eo.?",
		".?.eow",
		".?e.ow",
		".?eo.w",
		"e.?ow",
		".?oew",
		".?ewo",
		".?.?ow",
		"m.?ow",
		"m.?.?w",
		"m.?o.?",
		"m..?ow",
		"m.?.ow",
		"m.?o.w",
		".?mow",
		"mo.?w",
		"m.?wo",
		".?e.?w",
		"m.?.?w",
		"me.?w",
		"me.?.?",
		"m.e.?w",
		"me..?w",
		"me.?.w",
		"em.?w",
		"m.?ew",
		"mew.?",
		".?eo.?",
		"m.?o.?",
		"me.?.?",
		"meo.?",
		"m.eo.?",
		"me.o.?",
		"meo..?",
		"emo.?",
		"moe.?",
		"me.?o",
		".?.eow",
		"m.?eow",
		"m..?ow",
		"m.e.?w",
		"m.eo.?",
		"m..eow",
		"m..eow",
		"m.e.ow",
		"m.eo.w",
		".meow",
		"me.ow",
		"m.oew",
		"m.ewo",
		".?e.ow",
		"m.?.ow",
		"me.?ow",
		"me..?w",
		"me.o.?",
		"m.e.ow",
		"me..ow",
		"me..ow",
		"me.o.w",
		"em.ow",
		"m.eow",
		"meo.w",
		"me.wo",
		".?eo.w",
		"m.?o.w",
		"me.?.w",
		"meo.?w",
		"meo..?",
		"m.eo.w",
		"me.o.w",
		"meo..w",
		"meo..w",
		"emo.w",
		"moe.w",
		"me.ow",
		"meow.",
		".?mow",
		"e.?ow",
		"em.?w",
		"emo.?",
		"e.mow",
		"em.ow",
		"emo.w",
		"meow",
		"eomw",
		"emwo",
		".?oew",
		"m.?ew",
		"mo.?w",
		"moe.?",
		"m.oew",
		"mo.ew",
		"moe.w",
		"omew",
		"meow",
		"mowe",
		".?ewo",
		"m.?wo",
		"me.?o",
		"mew.?",
		"m.ewo",
		"me.wo",
		"mew.o",
		"emwo",
		"mweo",
		"meow"
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
