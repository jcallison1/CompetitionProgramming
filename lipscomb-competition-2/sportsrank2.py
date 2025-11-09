# for i in range(int(input())):
#     scores = [int(s) for s in input().split()[1:]]

#     scores.sort(reverse=True)

#     last = None
#     has_dup = False
#     benefit = 0
    
#     for s in scores:
#         if last == s:
#             has_dup = True
        
#         elif has_dup and last != s:
#             benefit += 1

#         last = s
    
#     print(benefit)

from collections import Counter

for x in range(int(input())):
    scores = [int(s) for s in input().split()[1:]]
    scores.sort(reverse=True)

    # score_counts = Counter(scores)
    # set_ver = list(set(scores))

    # ahead = 1
    # ahead2 = 1
    # score_comp = [0] * len(scores)

    # for x in range(len(scores)):
    #     if scores[x] == scores[x+1]:
    #         score_comp[x] = ahead
    #         score_comp[x+1] = ahead
    #         ahead2 += 1
    #     else:
    #         ahead += ahead2
    #         ahead2 = 1
    #         score_comp[x+1] = ahead

    # score_set = list(set(score_comp))

    # answer = 0

    # for x in range(len(score_set)):
    #     if score_set[x] > x + 1:
    #         answer += (1 * score_counts[scores[x]])

    # print(answer)

    # answer = 0
    # last = -1
    # begin_dup_place = -1
    # score_dense = 0

    # for i, score in enumerate(scores):
    #     if score == last:
    #         comp_score = begin_dup_place
    #     else:
    #         begin_dup_place = i

    #         comp_score = i
    #         score_dense += 1

    #     if score_dense > comp_score:
    #         answer += 1

    #     last = score
    
    last = -1
    last_last = -1
    current_place = 0
    dense_places = list()

    for i, score in enumerate(scores):
        if score != last:
            current_place += 1

        dense_places.append(current_place)

        last_last = last
        last = score
    
    last = -1
    ahead = 1
    current_place = 0
    comp_places = list()

    for i, score in enumerate(scores):
        if score == last:
            ahead += 1
        else:
            current_place += ahead
            ahead = 1
        
        comp_places.append(current_place)

        last = score
    
    answer = 0

    for a, b in zip(comp_places, dense_places):
        if a != b:
            answer += 1
    
    # print(comp_places)
    # print(dense_places)
    # print()
    print(answer)
    
    