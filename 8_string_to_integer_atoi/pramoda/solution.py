class Solution:
    def myAtoi(self, s: str) -> int:
        buf = []
        s = s.strip()
        if s == "":
            return 0
        if (s[0] == '-' or s[0] == '+'):
            buf.append(s[0])
            s = s[1:]
        for i in range(len(s)):
            if s[i].isdigit():
                buf.append(s[i])
            else:
                break
        
        num_str = "".join(buf)
        if (num_str == "" or num_str == "-" or num_str == "+"):
            return 0
        return max(min(int(num_str), 2**31 - 1), -2**31)

s = Solution()
print(s.myAtoi("42"))