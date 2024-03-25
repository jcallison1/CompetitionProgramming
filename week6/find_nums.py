nums = {
	"1": (0, 0),
	"2": (1, 0),
	"3": (2, 0),
	"4": (0, 1),
	"5": (1, 1),
	"6": (2, 1),
	"7": (0, 2),
	"8": (1, 2),
	"9": (2, 2),
	"0": (1, 3),
}

for i in range(10):
	for j in range(10):
		for k in range(10):
			x1, y1 = nums[str(i)]
			x2, y2 = nums[str(j)]
			x3, y3 = nums[str(k)]
			
			if x1 <= x2 and x2 <= x3:
				if y1 <= y2 and y2 <= y3:
					print(str(i) + str(j) + str(k))
