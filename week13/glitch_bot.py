import itertools
from enum import Enum

targets = input().split()
target_x = int(targets[0])
target_y = int(targets[1])

class Direction(Enum):
	North = 1
	East = 2
	South = 3
	West = 4

class Movement:
	currentDirection = Direction.North
	turningDirection = None
	x = 0
	y = 0
   
	def rotateAndMove(self, turning):
		if turning == 'left':
			if self.currentDirection == Direction.North:
				self.currentDirection = Direction.West
			else:
				self.currentDirection = Direction(self.currentDirection.value - 1)
		elif turning == 'right':
			if self.currentDirection == Direction.West:
				self.currentDirection = Direction.North
			else:
				self.currentDirection = Direction(self.currentDirection.value + 1)
		else: # command is forward
			if self.currentDirection == Direction.North:
				self.y += 1
			elif self.currentDirection == Direction.East:
				self.x += 1
			elif self.currentDirection == Direction.South:
				self.y -= 1
			elif self.currentDirection == Direction.West:
				self.x -= 1
	
	def execute_instructions(self, instructions: list[str]):
		for instruction in instructions:
			self.rotateAndMove(instruction)

def main():
	inst_count = int(input())
	instructions = [input().lower() for _ in range(inst_count)]

	for i in range(inst_count):
		for replacement in ["Left", "Right", "Forward"]:
			instructions2 = list(instructions)
			instructions2[i] = replacement.lower()
			
			m = Movement()
			m.execute_instructions(instructions2)
			
			if m.x == target_x and m.y == target_y:
				print(f"{i + 1} {replacement}")
				return

main()