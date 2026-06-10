class Solution:
    def longestPalindrome(self, s: str) -> str:
        def exploreOdd(s, l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1:r]
        def exploreEven(s, l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1:r]
        if len(s) < 2:
            return s
        
        longest = ""
        for i in range(len(s)):
            odd = exploreOdd(s, i, i)
            even = exploreEven(s, i, i + 1)
            longest = max(longest, odd, even, key=len)
        return longest

s = Solution()
print(s.longestPalindrome("abccccdd"))
