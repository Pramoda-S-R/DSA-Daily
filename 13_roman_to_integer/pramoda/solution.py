class Solution:
    def romanToInt(self, s: str) -> int:
        roman_map = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        num = 0
        last_num = 0
        for i in range(len(s)-1, -1, -1):
            n = roman_map[s[i]]
            if n < last_num:
                num -= n
            else:
                num += n

            last_num = n

        return num
    
s = Solution()
print(s.romanToInt("MCMXCIV"))