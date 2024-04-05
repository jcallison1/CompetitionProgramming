import functools

time_limit = int(input())
meals = [int(input()) for _ in range(int(input()))]

@functools.lru_cache(maxsize=None)
def count_ways(remaining_time: int):
	if remaining_time < 0: return 0
	if remaining_time == 0: return 1
	
	ways = 0
	
	for time in meals:
		ways += count_ways(remaining_time - time)
	
	return ways

print(count_ways(time_limit))
