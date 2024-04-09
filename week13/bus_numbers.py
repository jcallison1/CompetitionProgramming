input()
buses = sorted(map(int, input().split()))
buses.append(0)

output = list()
range_start = buses[0]

for i in range(len(buses) - 1):
	if buses[i] + 1 != buses[i + 1]:
		if range_start == buses[i]:
			output.append(str(range_start))
		elif range_start == buses[i - 1]:
			output.append(str(range_start))
			output.append(str(buses[i]))
		else:
			output.append(f"{range_start}-{buses[i]}")
		
		range_start = buses[i + 1]

print(" ".join(output))
