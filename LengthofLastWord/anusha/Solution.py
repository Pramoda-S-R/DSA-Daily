class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        
        for i in range(len(s) - 1, -1, -1):
            char = s[i]
            
            if "a" <= char.lower() <= "z":
                count += 1
            elif char == ' ' and count > 0:
                break
                
        return count
