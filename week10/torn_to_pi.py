from collections import defaultdict
import math
from typing import NamedTuple

class Node:
	name: str
	edges: set[str]
	dist: int
	prev: str | None
	
	def __init__(self) -> None:
		self.name = ""
		self.edges = set()
		self.dist = math.inf
		self.prev = None

node_count = int(input())

graph = defaultdict(Node)

for _ in range(node_count):
	line = input().split()
	node_name = line[0]
	
	graph[node_name].name = node_name
	graph[node_name].edges |= set(line[1:])
	
	for other in line[1:]:
		graph[other].edges.add(node_name)
		graph[other].name = other

src_node, dst_node = input().split()

graph[src_node].dist = 0

unvisted = list(graph.values())

while unvisted:
	min_node = min(unvisted, key=lambda n: n.dist)
	unvisted.remove(min_node)
	
	for other_name in min_node.edges:
		other_node = graph[other_name]
		
		if other_node in unvisted:
			new_dist = min_node.dist + 1
			
			if new_dist < other_node.dist:
				other_node.dist = new_dist
				other_node.prev = min_node.name

# for node in graph.values():
# 	print(f"{node.name} - {node.prev}")

current_node = graph[dst_node]

if current_node.dist == math.inf:
	print("no route found")
else:
	path = list()
	
	while True:
		path.append(current_node.name)
		
		if current_node.prev is None: break
		current_node = graph[current_node.prev]
	
	path.reverse()
	
	print(" ".join(path))
