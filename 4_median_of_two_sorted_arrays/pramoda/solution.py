class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        i = 0
        j = 0

        m = len(nums1)
        n = len(nums2)

        m1 = -1
        m2 = -1

        for _ in range((m + n) // 2 + 1):
            m2 = m1

            if i != m and j != n:
                if nums1[i] > nums2[j]:
                    m1 = nums2[j]
                    j += 1
                else:
                    m1 = nums1[i]
                    i += 1
            elif i < m:
                m1 = nums1[i]
                i += 1
            else:
                m1 = nums2[j]
                j += 1

        if (m+n) % 2 == 1:
            return m1
        else:
            return (m1 + m2) / 2.0

s = Solution()
print(s.findMedianSortedArrays([1, 2, 3], [200, 250]))