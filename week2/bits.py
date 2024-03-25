count = int(input())

for i in range(count):
	full_num = input()
	
	num = ""
	max_ones = 0
	
	for digit in full_num:
		num += digit
		
		ones = sum((b == "1" for b in bin(int(num))))
		
		if ones > max_ones:
			max_ones = ones
	
	print(max_ones)