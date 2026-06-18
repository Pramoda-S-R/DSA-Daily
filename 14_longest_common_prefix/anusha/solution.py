class Solution:
    def longestCommonPrefix(self, v: list[str]) -> str:
        for i in range(len(v[0])):
            char = v[0][i]

            for string in v[1:]:
                if i == len(string) or string[i] != char:
                     return v[0][:i]  
                       
        return v[0]


s = Solution()
print(s.longestCommonPrefix(["flower","flow","flight"]))