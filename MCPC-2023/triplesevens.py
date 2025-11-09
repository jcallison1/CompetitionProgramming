count = int(input())

wheel1 = [int(s) for s in input().split()]
wheel2 = [int(s) for s in input().split()]
wheel3 = [int(s) for s in input().split()]

if 7 in wheel1 and 7 in wheel2 and 7 in wheel3:
    print("777")
else:
    print("0")
