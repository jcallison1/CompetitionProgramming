import itertools
import collections

num_groups = int(input())

groups = list()

for _ in range(num_groups):
    size = int(input())

    group = list()

    for _ in range(size):
        player = tuple(int(i) for i in input().split())

        group.append(player)
    
    groups.append(group)

possible_groups = 0

for group1, group2 in itertools.combinations(groups, 2):
    if (len(group1) + len(group2)) < 15: continue

    roles = collections.defaultdict(list)
    index = 0

    for player in group1:
        roles[player[0]].append(index)
        roles[player[1]].append(index)

        index += 1
    
    for player in group2:
        roles[player[0]].append(index)
        roles[player[1]].append(index)

        index += 1
    
    works = True

    for player in group1:
        if len(roles[player[0]]) == 1 and len(roles[player[1]]) == 1:
            works = False
            break
    
    for player in group2:
        if len(roles[player[0]]) == 1 and len(roles[player[1]]) == 1:
            works = False
            break
    
    if works and len(roles) == 15:
        possible_groups += 1

    # for people in roles.values():
    #     if len(people) == 1:
    #         for person in people:
    #             for people in roles.values():
    #                 if person in people:
    #                     people.remove(person)

    # if sum(len(people) for people in roles.values()) == 15:
    #     possible_groups += 1

print(possible_groups)
