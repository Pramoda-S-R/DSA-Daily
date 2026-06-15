class Solution:
    def corpFlightBookings(self, bookings: list[list[int]], n: int) -> list[int]:
        out = [0] * (n + 1)

        for first, last, seats in bookings:
            out[first-1] += seats
            out[last] -= seats

        for i in range(1, n):
            out[i] += out[i - 1]

        return out[:-1]

s = Solution()
print(s.corpFlightBookings([[1,2,10],[2,3,20],[2,5,25]], 5))