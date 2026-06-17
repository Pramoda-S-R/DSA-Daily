class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        phone_layout = {
        "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
        "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        combinations = [""]
        for digit in digits:
            if digit in phone_layout:
                combinations = [prefix + letter for prefix in combinations for letter in phone_layout[digit]]
        return combinations
