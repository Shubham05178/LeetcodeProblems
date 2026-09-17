class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)

        i = 0
        j = 0
        curr_sum = 0

        min_best_len_till_idx = [float('inf')] * n

        best_min_len = float('inf')
        result = float('inf')

        while j < n:
            curr_sum += arr[j]

            while i < j and curr_sum > target:
                curr_sum -= arr[i]
                i += 1

            if curr_sum == target:
                length = j - i + 1

                if i > 0 and min_best_len_till_idx[i - 1] != float('inf'):
                    result = min(result, length + min_best_len_till_idx[i - 1])

                best_min_len = min(best_min_len, length)
            min_best_len_till_idx[j] = best_min_len
            j += 1
        return -1 if result == float('inf') else result