import math

x1, y1, x2, y2, major_axis = [int(x) for x in input().split()]

mid_x = (x1 + x2) / 2
mid_y = (y1 + y2) / 2

bewteen_dist = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

major_radius = major_axis / 2
minor_radius = math.sqrt(major_radius**2 - (bewteen_dist / 2)**2)

theta = math.atan2(y1 - y2, x1 - x2)
print(theta)

min_x = math.inf
min_y = math.inf
max_x = -math.inf
max_y = -math.inf

for i in range(10000):
	alpha = (i / 10000) * 2*math.pi
	
	x = major_radius * (math.cos(alpha) * math.cos(theta) - math.sin(alpha) * math.sin(theta)) + mid_x
	y = minor_radius * (math.cos(alpha) * math.sin(theta) + math.sin(alpha) * math.cos(theta)) + mid_y
	
	min_x = min(min_x, x)
	min_y = min(min_y, y)
	max_x = max(max_x, x)
	max_y = max(max_y, y)

print(f"{min_x} {min_y} {max_x} {max_y}")
