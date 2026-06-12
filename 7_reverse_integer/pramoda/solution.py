class Solution:
    def reverse(self, x: int) -> int:
        MAX = 2_147_483_647

        sign = -1 if x < 0 else 1
        x = abs(x)

        rev = 0

        while x:
            digit = x % 10

            if rev > (MAX - digit) // 10:
                return 0

            rev = rev * 10 + digit
            x //= 10

        return sign * rev

s = Solution()
print(s.reverse(-120))
