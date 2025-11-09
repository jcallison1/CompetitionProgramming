def eval_expr(expr, inputs):
	op = expr.pop()
	
	var = "pqrst".find(op)
	
	if var != -1:
		return ((inputs >> var) & 1) != 0
	
	if op == "N":
		return not eval_expr(expr, inputs)
	
	a = eval_expr(expr, inputs)
	b = eval_expr(expr, inputs)
	
	if op == "K": return a and b
	if op == "A": return a or b
	if op == "C": return not a or b
	if op == "E": return a == b

while True:
	expr = input()
	if expr == "0": break
	
	expr = list(expr)
	expr.reverse()
	
	is_t = True
	
	for inputs in range(32):
		is_t = is_t and eval_expr(list(expr), inputs)
	
	print("tautology" if is_t else "not")
