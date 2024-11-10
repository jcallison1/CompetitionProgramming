w, h, n = [int(s) for s in input().split()]
powers = [int(s) for s in input().split()]

def divide(w, h):
	for i in range(n - 1, -1, -1):
		p = pow(2, i)
		