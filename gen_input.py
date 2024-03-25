import random

COUNT = 1_000_000
CMDS = 1_000_000
MAX = 2**30

print(f"{COUNT} {CMDS}")

for i in range(CMDS):
	if random.randint(0, 1) == 0:
		print(f"+ {random.randint(0, COUNT - 1)} {random.randint(-MAX, MAX)}")
	else:
		print(f"? {random.randint(0, COUNT - 1)}")
