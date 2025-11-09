class DisjoinSets:
    parent: list[int]
    rank: list[int]
    sizes: list[int]

    set_count: int

    def __init__(self, cap: int):
        self.parent = [i for i in range(cap)]
        self.rank = [0 for _ in range(cap)]
        self.sizes = [1 for _ in range(cap)]

        self.set_count = cap
    
    def find_set(self, x):
        if self.parent[x] == x:
            return x
        
        s = self.find_set(self.parent[x])
        self.parent[x] = s
        return s
    
    def join(self, a, b):
        a_set = self.find_set(a)
        b_set = self.find_set(b)

        if a_set == b_set: return

        if self.rank[a_set] > self.rank[b_set]:
            a_set, b_set = b_set, a_set
        
        self.parent[a_set] = b_set

        if self.rank[a_set] == self.rank[b_set]:
            self.rank[b_set] += 1
        
        self.sizes[b_set] += self.sizes[a_set]

        self.set_count -= 1

students, apps = [int(s) for s in input().split()]

all_sets = DisjoinSets(students)

for _ in range(apps):
    app = [int(s) - 1 for s in input().split()]
    sets = [all_sets.find_set(x) for x in app]
    sizes = [all_sets.sizes[x] for x in sets]

    # print(sizes, sets)

    if len(set(sizes)) == 1 or len(set(sets)) <= 2:
        all_sets.join(app[0], app[1])
        all_sets.join(app[0], app[2])
    
    print(all_sets.set_count)

