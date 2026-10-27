class Solution:
    def countStaircase(self, nums: list[int]) -> int:
        n = len(nums)
        size = max(nums) + 1
        positions = [None] * size
        occurrence = [0] * n

        for i, value in enumerate(nums):
            if positions[value] is None:
                positions[value] = []
            occurrence[i] = len(positions[value])
            positions[value].append(i)

        for indices in positions:
            if indices is not None:
                indices.append(n)

        seen = [0] * size
        answer = n

        for start, first in enumerate(nums):
            stamp = start + 1
            seen[first] = stamp
            right = positions[first][occurrence[start] + 1]
            left = start
            distinct = 1
            end = start

            for j in range(start + 1, right):
                if j >= right:
                    break

                value = nums[j]
                if seen[value] == stamp:
                    continue

                seen[value] = stamp
                distinct += 1
                end += distinct

                if end >= right:
                    break

                indices = positions[value]
                target = occurrence[j] + distinct - 1
                if target >= len(indices) - 1:
                    break

                left = max(left, indices[target])
                right = min(right, indices[target + 1])

                if left >= right or end >= right:
                    break

                if left <= end:
                    answer += 1

        return answer