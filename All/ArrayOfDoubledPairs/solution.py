class Solution:
    def canReorderDoubled(self, arr):
        lookup = {}
        for num in arr:
            if num in lookup:
                lookup[num] += 1
            else:
                lookup[num] = 1

        for num in sorted(arr, key=abs):
            if lookup[num] == 0:
                continue
            if 2 * num not in lookup or lookup[2 * num] == 0:
                return False
            lookup[num] -= 1
            lookup[2 * num] -= 1
        return True
