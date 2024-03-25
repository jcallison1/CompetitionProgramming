nums = input().split()
nums = [int(s) for s in nums]
nums.sort()

order = input()
nums_ordered = [str(nums[ord(s) - ord("A")]) for s in order]

print(" ".join(nums_ordered))
