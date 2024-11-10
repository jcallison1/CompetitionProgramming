left = 2
right = 999

while left <= right:
    mid = (left + right) // 2
    
    print(mid, flush=True)
    
    k = input()
    
    if k == "lower":
        left = mid + 1
    elif k == "higher":
        right = mid - 1
    else:
        break
