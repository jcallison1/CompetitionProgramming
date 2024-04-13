input()

cards = list(map(int, input().split()))

# player1_pos = 0
# player2_pos = 0

player1_strife = 0
player2_strife = 0

# player1_stack = list()
# player2_stack = list()

# turn = True

for i, c in enumerate(cards):
	if c == 0:
		if i % 2 == 0:
			player1_strife += 1
		else:
			player2_strife += 1

if player1_strife == player2_strife:
	print("Tie")
elif player1_strife > player2_strife:
	print("Player 2 wins")
else:
	print("Player 1 wins")
