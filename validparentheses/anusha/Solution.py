class Solution(object):
    def isValid(self, s):
        # We replace matching pairs until there are none left
        # If the string becomes empty, it was valid!
        while "()" in s or "[]" in s or "{}" in s:
            s = s.replace("()", "").replace("[]", "").replace("{}", "")
            
        return s == ""

