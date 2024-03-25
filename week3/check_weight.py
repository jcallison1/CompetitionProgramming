import sys

print(sum((ord(s) - ord('a') + 1 for s in sys.argv[1])))
