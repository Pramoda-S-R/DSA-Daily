class Solution:
    def longestPalindrome(self, s: str) -> str:
        def explore(s, l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1:r]

        if len(s) < 2:
            return s
        
        longest = ""
        for i in range(len(s)):
            odd = explore(s, i, i)
            even = explore(s, i, i + 1)
            longest = max(longest, odd, even, key=len)
        return longest

s = Solution()
print(s.longestPalindrome("abccccdd"))
