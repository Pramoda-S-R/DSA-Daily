from itertools import accumulate

class Solution:
    def maxSumRangeQuery(self, nums: list[int], requests: list[list[int]]) -> int:
        n = len(nums)
        d = [0]*(n+1)
        MOD = 1_000_000_007
        for start, end in requests:
            d[start] += 1
            d[end + 1] -= 1
        d = list(accumulate(d))

        d.sort(reverse=True)
        nums.sort(reverse=True)

        s = 0
        for num, freq in zip(nums,d):
            if freq == 0:
                break
            s = (s + num * freq) 

        return s % MOD

s = Solution()
print(s.maxSumRangeQuery([1, 2, 3, 4, 5, 10], [[0,2], [1,3], [1,1]]))