class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        
        n = len(haystack)
        m = len(needle)
    
    # Loop only where the needle can completely fit
        for i in range(n - m + 1):
        # Compare a slice of haystack with the needle
            if haystack[i : i + m] == needle:
                return i 
        return -1
