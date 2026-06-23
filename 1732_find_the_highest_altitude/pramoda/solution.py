from itertools import accumulate

class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        return max(list(accumulate([0] + gain)))


s = Solution()
print(s.largestAltitude([-5,1,5,0,-7]))