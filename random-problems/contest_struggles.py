total_count, solved_count = map(int, input().split())
total_avg, solved_avg = map(int, input().split())

g = (total_avg * total_count - solved_avg * solved_count) / (total_count - solved_count)

if 0 <= g <= 100:
	print(f"{g:.10f}")
else:
	print("impossible")
