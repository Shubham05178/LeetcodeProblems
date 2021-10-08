class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closestSum = None
        numsLen = len(nums)
        for i in range(numsLen - 2):
            start = i + 1
            end = numsLen - 1
            while start < end:
                tempSum = nums[i] + nums[start] + nums[end]
                if closestSum is None:
                    closestSum = tempSum
                elif abs(target - closestSum) > abs(target - tempSum):
                    closestSum = tempSum
                if tempSum == target:
                    break
                elif tempSum < target:
                    start += 1
                else:
                    end -= 1
        return closestSum
