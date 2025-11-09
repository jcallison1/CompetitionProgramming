import math

def dist(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1], p2[1])

def in_circ(p, c):
    center, radius = c
    return dist(p, center) <= radius + 1e-9

def circle_from(p1, p2, p3 = None):
    if p3 is None:
        cx = (p1[0] + p2[0]) / 2
        cy = (p1[1] + p2[1]) / 2
        r = dist(p1, p2) / 2
        return (cx, cy), r

    A = p2[0] - p1[0]
    B = p2[1] - p1[1]
    C = p3[0] - p1[0]
    D = p3[1] - p1[1]

    E = A * (p1[0]+p2[0]) + B * (p1[1]+p2[1])
    F = C * (p1[0]+p3[0]) + D * (p1[1]+p3[1])

    G = 2*(A*(p3[1] - p2[1]) - B*(p3[0]-p2[0])) 
    if G == 0: return circle_from(p1, p2)

    cx = (D*E - B*F) / G
    cy = (A*F - C*E) / G
    r = dist((cx, cy), p1)

    return (cx, cy), r

def mec_helper(points, boundary, n):
    if n == 0 or len(boundary) == 3:
        if len(boundary) == 0:
            return ((0, 0), 0)
        elif len(boundary) == 1:
            return (boundary[0], 0)
        elif len(boundary) == 2:
            return circle_from(boundary[0], boundary[1])
        else:
            return circle_from(boundary[0], boundary[1], boundary[2])

    p = points[n-1]
    d = mec_helper(points, boundary, n-1)
    if in_circ(p, d):
        return d
    return mec_helper(points, boundary + [p], n-1)

def mec(points):
    return mec_helper(points, [], len(points))

n = int(input())
p = []
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    p.append((x, y))

print(mec(p))