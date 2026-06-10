class Solution:
    def reverse(self, x: int) -> int:
        MAX = 2_147_483_647

        num = x
        neg = False

        if x < 0:
            neg = True
            num = -x

        res = 0
        while (num > 0):
            res = (res * 10) + (num % 10)
            num = num // 10

            if res > MAX:
                return 0
        
        return -res if neg else res

s = Solution()
print(s.reverse(-2147483648))
