test_cases = int(input())

for i in range(test_cases):
	num_a, src_lang, dest_lang = input().split()
	
	num = 0
	mult = 1
	
	for c in reversed(num_a):
		num += src_lang.index(c) * mult
		mult *= len(src_lang)
	
	out = ""
	
	while num > 0:
		out = dest_lang[num % len(dest_lang)] + out
		num //= len(dest_lang)
	
	print(f"Case #{i + 1}: {out}")
