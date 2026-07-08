class Solution(object):
    def countMajoritySubarrays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        ans = 0

        for i in range(n):
            target_count = 0
            for j in range(i, n):
                if nums[j] == target:
                    target_count += 1

                length = j - i + 1
            # Check if target appears strictly more than half of the times
                if target_count > length // 2:
                    ans += 1

        return ans
        
