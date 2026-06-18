class Solution:
    def passwordStrength(self, password: str) -> int:
        filtered = set(password)
        score = 0

        for char in filtered:

            if (char.islower()):
                score += 1
            elif (char.isupper()):
                score += 2
            elif (char.isdigit()):
                score += 3
            else:
                score += 5

        return score


s = Solution()
print(s.passwordStrength(password = "bbB11#"))