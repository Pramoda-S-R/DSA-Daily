import math
class Solution(object):
    def gcdOfOddEvenSums(self, n):

        """
        :type n: int
        :rtype: int
        """
        sumEven = 0
        sumOdd = 0
        
        # Iterating from 1 to 2*n (inclusive)
        for i in range(1, (n * 2) + 1):
            if i % 2 == 0:
                sumEven += i
            else:
                sumOdd += i
                
        # Return the Greatest Common Divisor of the two sums
        def gcd(a, b):
            while b != 0:
                a, b = b, a % b
            return abs(a)

        return gcd(sumEven, sumOdd)




