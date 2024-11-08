from typing import NamedTuple

card_count, max_mult = [int(x) for x in input().split()]

class Card(NamedTuple):
	t: str
	value: int

cards = list()

for _ in range(card_count):
	t, v = [int(x) for x in input().split()]
	cards.append(Card(t, int(v)))

def find_thing(pos: int, length: int) -> int:
	if length == 0: return 0
	if pos >= len(cards): return 0
	
	score = 0
	
	for card in cards[pos:pos + length]:
		if card.t == "a":
			score += card.value
		elif card.t == "m":
			score *= card.value
	
	
	
	return score