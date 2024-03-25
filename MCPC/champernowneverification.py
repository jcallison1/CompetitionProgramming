word = input()

valid = ["".join([str(i) for i in range(1, k + 1)]) for k in range(100)]

try:
    l = valid.index(word)
    print(l)
except:
    print("-1")