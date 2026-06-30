class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_pos = {'a': -1, 'b': -1, 'c': -1}
        count = 0
    
        for i, char in enumerate(s):
        # Update the position of the current character
            last_pos[char] = i
        
        # The smallest index among 'a', 'b', 'c' forms the valid starting point
        # Any substring starting from index 0 up to min_pos is valid
            min_pos = min(last_pos['a'], last_pos['b'], last_pos['c'])
        
            if min_pos != -1:
                count += min_pos + 1
            
        return count
        
