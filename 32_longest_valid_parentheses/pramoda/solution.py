class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        curr_len = 0
        max_len = 0 

        for c in s:
            if c == "(":
                stack.append(curr_len)
                curr_len = 0 
            elif stack:
                curr_len += stack.pop() + 2
                max_len = max(max_len, curr_len)
            else:
                curr_len = 0 
        
        return max_len


s = Solution()
print(s.longestValidParentheses(')())())'))