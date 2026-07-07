class Solution(object):
    def sumAndMultiply(self, n):


        if n == 0:
            return 0
            
        digit_sum = 0
        x = 0
        multiplier = 1
        
        # Process digits from right to left
        while n > 0:
            n, digit = divmod(n, 10) # Splits last digit and remaining number
            
            if digit != 0:
                digit_sum += digit
                x += digit * multiplier
                multiplier *= 10  # Shifts the position left for the next non-zero digit
                
        return x * digit_sum
