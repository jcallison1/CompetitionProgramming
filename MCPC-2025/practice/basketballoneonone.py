line = list(input())
line.reverse()

A = 0
B = 0

while line:
    p = line.pop()
    n = int(line.pop())

    if p == "A":
        A += n
    else:
        B += n
    
if A > B:
    print("A")
else:
    print("B")