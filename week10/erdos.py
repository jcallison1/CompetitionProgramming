from collections import defaultdict
import heapq
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

graph = defaultdict(Node)
main_nodes = list()

while True:
	try:
		line = input().split()
	except EOFError:
		break
	
	node_name = line[0]
	main_nodes.append(node_name)
	
	graph[node_name].name = node_name
	graph[node_name].edges |= set(line[1:])
	
	for other in line[1:]:
		graph[other].edges.add(node_name)
		graph[other].name = other

graph["PAUL_ERDOS"].dist = 0

queue = list()
visited = set()

for node in graph.values():
	heapq.heappush(queue, (node.dist, node.name))

while queue:
	_, min_node_name = heapq.heappop(queue)
	if min_node_name in visited: continue
	
	visited.add(min_node_name)
	
	min_node = graph[min_node_name]
	
	for other_name in min_node.edges:
		other_node = graph[other_name]
		
		if other_name not in visited:
			new_dist = min_node.dist + 1
			
			if new_dist < other_node.dist:
				other_node.dist = new_dist
				other_node.prev = min_node.name
				
				heapq.heappush(queue, (new_dist, other_name))

# for node in graph.values():
# 	print(f"{node.name} - {node.prev}")

for node_name in main_nodes:
	node = graph[node_name]
	print(f"{node_name} {'no-connection' if node.dist == math.inf else node.dist}")
