def reverse_dir(line):
    new_line = list()

    for c in line:
        match c:
            case "<": c = ">"
            case ">": c = "<"

            case "{": c = "}"
            case "}": c = "{"

            case "(": c = ")"
            case ")": c = "("

        new_line.append(c)
    
    new_line.reverse()
    return "".join(new_line)

EYES = set("\"*'")
SCALES = set("})")

def count_fish(line):
    i = -1
    fish_counts = [0] * 3

    while i < len(line):
        i += 1

        try:
            if line[i] != "<": continue

            eye = line[i + 1]
            if eye not in EYES: continue

            scale = line[i + 2]
            if scale not in SCALES: continue
            # if line[i + 3] not in SCALES or line[i + 3] != scale: continue

            j = 3
            while line[i + j] in SCALES and line[i + j] == scale:
                j += 1

            if line[i + j] != ">": continue
            if line[i + j + 1] != "<": continue

            fish_counts["\"*'".index(eye)] += 1
        except:
            break
    
    return fish_counts

for _ in range(int(input())):
    h, w = [int(s) for s in input().split()]

    # lines = [input()[:w] for _ in range(h)]

    fish_counts = [0] * 3

    for _ in range(h):
        line = input()

        c1 = count_fish(line)
        c2 = count_fish(reverse_dir(line))
        # print(reverse_dir(line))
        # print(c1)

        for i in range(3):
            fish_counts[i] += c1[i] + c2[i]
    
    print(f"{fish_counts[0]} {fish_counts[1]} {fish_counts[2]}")

