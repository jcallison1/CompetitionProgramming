mapping = {
(
"xxxxx",
"x...x",
"x...x",
"x...x",
"x...x",
"x...x",
"xxxxx",
): "0",
(
"....x",
"....x",
"....x",
"....x",
"....x",
"....x",
"....x",
): "1",
(
"xxxxx",
"....x",
"....x",
"xxxxx",
"x....",
"x....",
"xxxxx",
): "2",
(
"xxxxx",
"....x",
"....x",
"xxxxx",
"....x",
"....x",
"xxxxx",
): "3",
(
"x...x",
"x...x",
"x...x",
"xxxxx",
"....x",
"....x",
"....x",
): "4",
(
"xxxxx",
"x....",
"x....",
"xxxxx",
"....x",
"....x",
"xxxxx",
): "5",
(
"xxxxx",
"x....",
"x....",
"xxxxx",
"x...x",
"x...x",
"xxxxx",
): "6",
(
"xxxxx",
"....x",
"....x",
"....x",
"....x",
"....x",
"....x",
): "7",
(
"xxxxx",
"x...x",
"x...x",
"xxxxx",
"x...x",
"x...x",
"xxxxx",
): "8",
(
"xxxxx",
"x...x",
"x...x",
"xxxxx",
"....x",
"....x",
"xxxxx",
): "9",
(
".....",
"..x..",
"..x..",
"xxxxx",
"..x..",
"..x..",
".....",
): "+"

}

lines = [input() for _ in range(7)]

chars = [list() for _ in range((len(lines[0]) + 1) // 6)]

for line in lines:
	for i in range(len(chars)):
		chars[i].append(line[i * 6:i * 6 + 5])

text = "".join([mapping[tuple(c)] for c in chars])

num1, num2 = map(int, text.split("+"))
final_sum = num1 + num2

inverse_mapping = {c: l for l, c in mapping.items()}

out_chars = [inverse_mapping[c] for c in str(final_sum)]

for line_num in range(7):
	line_seg = [c[line_num] for c in out_chars]
	print(".".join(line_seg))
