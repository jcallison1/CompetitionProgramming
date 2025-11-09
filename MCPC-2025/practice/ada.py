
nums = list(map(int, input().split()))[1:]

rows = [nums]

while rows and len(set(rows[-1])) != 1:
    row = rows[-1]
    new_row = []

    for i in range(1, len(row)):
        new_row.append(row[i] - row[i - 1])
    
    rows.append(new_row)

a = 0

for i in range(len(rows)):
    # print(rows[i])
    a += rows[i][-1]

print(len(rows) - 1, a)