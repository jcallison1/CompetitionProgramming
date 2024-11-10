n = int(input())

small = 99999999999999999999
big = 0

for i in range(n):
	price = int(input())
	
	small = min(small, price)
	big = max(big, price)

k = small - big // 2

if k < 0:
	print(0)
else:
	print(k)
