# best = 0
# best_word = None
# last_word = None
# last_occ = 0

# for word in input().split():
#     if word == last_word:
#         last_occ += 1
#     else:
#         last_word = word

#         if last_occ > best:
#             best = last_occ
#             best_word = last_word
        
#         last_occ = 1

# if last_occ > best:
#     best = last_occ
#     best_word = last_word

# print(best_word)
import itertools
print(max(itertools.groupby(input().split()), key=lambda x: len(list(x[1])))[0])