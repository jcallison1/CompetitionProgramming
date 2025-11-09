S = input()
P = input()

s = {P}

for k in set(s):
    for i in range(0, 10):
        s.add(k + str(i))

for k in set(s):
    for i in range(0, 10):
        s.add(str(i) + k)

for k in set(s):
    s.add("".join(h.lower() if h.isupper() else h.upper() for h in k))

# print(s)

if S in s:
    print("Yes")
else:
    print("No")