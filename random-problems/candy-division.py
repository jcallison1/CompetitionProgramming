import math

n = int(input())
nums = set()

for x in range(1, math.ceil(math.sqrt(n)) + 1):
	if n % x == 0:
		nums.add(x - 1)
		nums.add(n // x - 1)

nums = list(nums)
nums.sort()

print(" ".join(str(x) for x in nums))
