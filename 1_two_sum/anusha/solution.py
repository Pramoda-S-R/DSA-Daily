class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
                for j in range(i + 1, len(nums)):
                    current_sum = nums[i] + nums[j]
                
                # Return the indices as a list of integers instead of printing a string
                    if current_sum == target:
                        return [i, j]

s = Solution()

nums = [2, 7, 11, 15]
target = 9

print(s.twoSum(nums, target))