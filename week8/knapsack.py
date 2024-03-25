# import sys

# input = sys.stdin.readline

while True:
	try:
		cap, size = [int(s) for s in input().split()]
		
		things = [tuple(int(s) for s in input().split()) for _ in range(size)]
	except (EOFError, ValueError):
		break
	
	cache = dict()
	chain = dict()
	
	def search(index, weight_remaining):
		global chain, things
		
		if weight_remaining <= 0 or index >= len(things):
			return 0
		
		cache_key = (index, weight_remaining)
		
		if cache_key in cache:
			return cache[cache_key]
		
		value, weight = things[index]
		
		outside = search(index + 1, weight_remaining)
		inside = (search(index + 1, weight_remaining - weight) + value) if weight_remaining >= weight else 0
		
		result = max(inside, outside)
		
		if result == inside:
			chain[cache_key] = ((index + 1, weight_remaining - weight), index)
		else:
			chain[cache_key] = chain.get((index + 1, weight_remaining))
		
		cache[cache_key] = result
		return result
	
	best_value = search(0, cap)
	# print(best_value)
	
	steps = list()
	current = chain.get((0, cap))
	
	while current != None:
		steps.append(current[1])
		current = chain.get(current[0])
	
	print(len(steps))
	print(" ".join(str(x) for x in steps))
