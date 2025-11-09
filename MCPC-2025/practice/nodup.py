s = set()

for w in input().split():
    if w in s:
        print("no")
        break
    
    s.add(w)
else:
    print("yes")