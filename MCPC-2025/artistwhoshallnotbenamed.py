n = int(input())


arr = list()

for i in range(n):
    arr.append(input())

boring = 0
cool = 0
artistic = 0

def get_bytes(string):
    char_list = list()

    for i in range(1, len(string), 2):
        char_list.append(string[i-1] + string[i])

    return char_list

# #0: boring, 1: cool, 2: artistic
# for i in arr:
#     char_list = get_bytes(i)
#     print(char_list)

#     tracking = 0
#     for c in char_list:
#         if c & 0x10000000:
#             continue

for s in arr:
    b = bytes(int(h, 16) for h in get_bytes(s))
    # print(b)
    try:
        q = b.decode("utf-8")

        for c in q:
            if ord(c) > 128:
                cool += 1
                break
        else:
            boring += 1
    except UnicodeError:
        artistic += 1

print(boring, cool, artistic)