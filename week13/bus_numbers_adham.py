stops = int(input())

buses = input()

buses = buses.split()

res = [int(i) for i in buses] #convert to ints

res.sort()
res.append(0)

flag = False #do we have a range

x = 0

while(x < stops):
    if (stops == x):
        print(beginning,end="")
        break
    beginning = res[x]
    hold = res[x+1]
    if (hold - beginning == 1):
        hold = res[x+1]
        flag = True
    if (beginning == hold):
        if flag:
            print(beginning,"-",hold)
        else:
            print(beginning,end="")
    x+=1