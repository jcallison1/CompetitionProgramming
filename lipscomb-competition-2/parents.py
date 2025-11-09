from collections import defaultdict
from typing import NamedTuple

class Node(NamedTuple):
    depth: int
    name: str

for _ in range(int(input())):
    graph = list()

    for id in range(int(input())):
        parent, name = input().split()
        parent = int(parent)

        if parent == -1:
            graph.append(Node(0, name))
        else:
            graph.append(Node(graph[parent].depth + 1, name))
    
    out = list()
    current_depth = -1

    for node in graph:
        if node.depth > current_depth:
            out.clear()
            current_depth = node.depth
        
        if node.depth == current_depth:
            out.append(node.name)
    
    out.sort()
    print(" ".join(out))

