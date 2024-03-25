num_squares = int(input())
costs = [int(input()) for _ in range(num_squares)]

cache = dict()

def search(index, jump_length):
	global costs, cache
	
	if (index, jump_length) in cache:
		return cache[(index, jump_length)]
		
	if index < 0 or index >= len(costs):
		return 9999999999999999
	
	if index == len(costs) - 1:
		return costs[index]
	
	cache[(index, jump_length)] = 9999999999999999
	
	result = min(
		search(index + jump_length + 1, jump_length + 1),
		search(index - jump_length, jump_length)
	) + costs[index]
	
	cache[(index, jump_length)] = result
	return result

print(search(1, 1))
