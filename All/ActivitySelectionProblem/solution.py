class Solution:
    def maxActivities(self, activities):
        # Sort activities by finish time.
        activities.sort(key=lambda x: x[1])
        totalActivityCount = len(activities)
        # First activity is always chosen.
        maxActivitiesCount = 1
        i = 1
        j = 0
        for i in range(1, totalActivityCount):
            if activities[i][0] >= activities[j][1]:
                maxActivitiesCount += 1
                j = i
            i += 1
        return maxActivitiesCount
