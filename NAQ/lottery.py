n = int(input())

ocs = [0 for _ in range(51)]

for i in range(n * 10):
	nums = [int(x) for x in input().split()]
	
	for num in nums:
		ocs[num] += 1

k = list()

for num, oc in enumerate(ocs):
	if oc > 2*n:
		k.append(str(num))

if k:
	print(" ".join(k))
else:
	print("-1")
