import math

def line_dist_hori(point_x, point_y, endpoint1_x, endpoint2_x, endpoints_y):
	if endpoint1_x <= point_x <= endpoint2_x:
		return abs(endpoints_y - point_y)
	
	endpoint_x = endpoint1_x if point_x < endpoint1_x else endpoint2_x
	
	return math.sqrt((endpoint_x - point_x)**2 + (endpoints_y - point_y)**2)

def line_dist_vert(point_x, point_y, endpoint1_y, endpoint2_y, endpoints_x):
	return line_dist_hori(point_y, point_x, endpoint1_y, endpoint2_y, endpoints_x)

post_x, post_y, min_x, min_y, max_x, max_y = map(int, input().split())

min_dist = min(
	line_dist_hori(post_x, post_y, min_x, max_x, min_y),
	line_dist_hori(post_x, post_y, min_x, max_x, max_y),
	
	line_dist_vert(post_x, post_y, min_y, max_y, min_x),
	line_dist_vert(post_x, post_y, min_y, max_y, max_x)
)

print(f"{min_dist:.10f}")
