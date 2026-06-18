class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = ""
        max_len = 0
        
        for char in s:
            if char in window:
                dupind = window.index(char)
                window = window[dupind + 1:]
            window += char
            max_len = max(max_len, len(window)) 
        return max_len


s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))