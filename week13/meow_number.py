num = int(input())

for i in range(200, 0, -1):
	if num % i**9 == 0:
		print(i)
		break
