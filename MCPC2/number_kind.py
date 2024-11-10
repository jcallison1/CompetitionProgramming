import math


n = int(input())

for i in range(n):
	num = int(input())
	
	out = ""
	
	if num % 2 == 1:
		out += "O"
	
	if math.sqrt(num) == int(math.sqrt(num)):
		out += "S"
	
	if out:
		print(out)
	else:
		print("EMPTY")