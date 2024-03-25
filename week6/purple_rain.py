def main():
	line = input()
	
	best_sum = -9999999999
	current_sum = 0
	current_sum_abs = 0
	
	for c in line:
		el = 1 if c == "R" else -1
		
		current_sum = max(x, current_sum + x)
		best_sum = max(best_sum, current_sum)
	
	return best_sum
	
main()
