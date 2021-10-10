class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        lookup = {}
        for i in range(len(nums)):
            lookup[i] = []
            k = nums[i]
            while True:
                lookup[i].append(k)
                # If the numer is about to repeat then calculate its length and break
                if k == i:
                    lookup[i] = len(lookup[i])
                    break
                # If number k is already present in lookup then its length will be same as lengthn of number k
                if k in lookup:
                    lookup[i] = lookup[k]
                    break
                k = nums[k]
        return max(lookup.values())
