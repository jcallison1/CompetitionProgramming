# def nth_root(num, n):
# 	x = num
	
# 	while True:
# 		new_x = x - (x**n - num) / (n * x**(n - 1))
		
# 		if new_x == x:
# 			return new_x
		
# 		x = new_x

# print(nth_root(3**23, 23))

while True:
	num = int(input())
	if num == 0: break
	
	for p in range(33, 1, -1):
		b = int(float(abs(num))**(1.0 / p))
		# b = int(nth_root(num, p))
		
		if b**p == num:
			print(p)
			break
	else:
		print(1)
