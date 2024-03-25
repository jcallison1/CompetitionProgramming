from collections import defaultdict
import heapq
import math
from typing import NamedTuple

class Edge(NamedTuple):
	to: int
	weight: int

class Node:
	id: int
	to_pickup: int
	edges: list[Edge]
	
	dist: int
	best_pickup: int
	prev: int | None
	
	def __init__(self, id, to_pickup) -> None:
		self.id = id
		self.to_pickup = to_pickup
		
		self.edges = list()
		self.dist = math.inf
		self.best_pickup = 0
		self.prev = None

node_count = int(input())

graph: list[Node] = list()

for i, to_pickup in enumerate(input().split()):
	graph.append(Node(i, int(to_pickup)))

edge_count = int(input())

for i in range(edge_count):
	node1, node2, weight = [int(s) for s in input().split()]
	
	node1 -= 1
	node2 -= 1
	
	graph[node1].edges.append(Edge(node2, weight))
	graph[node2].edges.append(Edge(node1, weight))

graph[0].dist = 0
graph[0].best_pickup = graph[0].to_pickup

queue = list()
visited = set()

for node in graph:
	heapq.heappush(queue, (node.dist, -node.best_pickup, node.id))

while queue:
	_, _, min_node_id = heapq.heappop(queue)
	
	if min_node_id in visited: continue
	visited.add(min_node_id)
	
	min_node = graph[min_node_id]
	
	for edge in min_node.edges:
		other_node = graph[edge.to]
		
		if edge.to not in visited:
			new_dist = min_node.dist + edge.weight
			new_pickup = min_node.best_pickup + other_node.to_pickup
			
			if new_dist < other_node.dist or (new_dist == other_node.dist and new_pickup > other_node.best_pickup):
				other_node.dist = new_dist
				other_node.best_pickup = new_pickup
				other_node.prev = min_node_id
				
				heapq.heappush(queue, (new_dist, -new_pickup, edge.to))

# for node in graph.values():
# 	print(f"{node.name} - {node.prev}")

dest_node = graph[node_count - 1]

if dest_node.dist == math.inf:
	print("impossible")
else:
	print(f"{dest_node.dist} {dest_node.best_pickup}")
