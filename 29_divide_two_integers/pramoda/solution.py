class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        MAX_POS = 2_147_483_647
        MAX_NEG = -2_147_483_648
        
        q = int(dividend/divisor)
        
        if q < 0:
            if q < MAX_NEG:
                return MAX_NEG
        else:
            if q > MAX_POS:
                return MAX_POS
        
        return q

s = Solution()
print(s.reverse(-2147483648))
