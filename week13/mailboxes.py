import functools

@functools.lru_cache(maxsize=None)
def dp(start: int, end: int, remaining_boxes: int):
	if end - start <= 0:
		return 99999999999999
	
	if end - start <= 1:
		return start
	
	if remaining_boxes <= 1:
		return sum(range(start, end))
	
	result = 99999999999999
	
	for pivot in range(start, end):
		result = min(result, dp(pivot + 1, end, remaining_boxes - 1))
		
		# result = min(result, max(
		# 	dp(start, pivot, remaining_boxes),
		# 	dp(pivot + 1, end, remaining_boxes - 1)
		# ))
	
	return result

for _ in range(int(input())):
	boxes, max_crackers = map(int, input().split())
	
	print(dp(0, max_crackers + 1, boxes))
