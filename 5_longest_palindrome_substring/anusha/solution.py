class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = "^#" + "#".join(s) + "#$"
        n = len(t)
    # p[i] stores the radius of the palindrome centered at t[i]
        p = [0] * n 
        center = 0
        right = 0
        for i in range(1, n - 1):
        # Find the mirror of index i with respect to the current center
            mirror = 2 * center - i
        # If i is within the right boundary, initialize p[i] using symmetry
            if i < right:
                p[i] = min(right - i, p[mirror])
        # Attempt to expand the palindrome centered at i
            while t[i + 1 + p[i]] == t[i - 1 - p[i]]:
                p[i] += 1
        # If the expanded palindrome extends past right, update center and right
            if i + p[i] > right:
                center = i
                right = i + p[i]
    # Step 3: Find the maximum radius and its center index
        max_len, center_index = max((val, idx) for idx, val in enumerate(p))
    # Step 4: Map back to the original string indices
        start = (center_index - max_len) // 2
        return s[start : start + max_len]

s = Solution()
print(s.longestPalindrome("babad"))