def perm(M: tuple[tuple[int]]) -> int:
    # print(M)

    if len(M) == 1:
        return M[0][0]
    if len(M) == 2:
        return M[0][0] * M[1][1] + M[0][1] * M[1][0]
    
    n = len(M)
    ans = 0

    for i in range(n):
        j = 0
        # for j in range(n):
        new_M = list()

        for r in range(n):
            if r == i: continue
            row = list()

            for c in range(n):
                if c == j: continue
                row.append(M[r][c])
            
            new_M.append(row)
        
        ans += M[i][j] * perm(new_M)
    
    return ans

N = int(input())
mat = [list(map(int, input().split())) for _ in range(N)]

print(perm(mat))

