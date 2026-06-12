class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        MAX_POS = 2_147_483_647
        MAX_NEG = -2_147_483_648

        if dividend == MAX_NEG and divisor == -1:
            return MAX_POS
        
        q = int(dividend/divisor)
        return q

s = Solution()
print(s.reverse(-2147483648))
