class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        hour_angles_dict = {}  
        for h in range(12):
            hour_angles_dict[h] = h * 30
        normalized_hour = hour % 12
        base_hour_angle = hour_angles_dict[normalized_hour]
        hour_hand_angle = base_hour_angle + (0.5 * minutes)
        minute_hand_angle = 6 * minutes
        angle_difference = abs(hour_hand_angle - minute_hand_angle)
        smaller_angle = min(angle_difference, 360 - angle_difference)
        return float(smaller_angle)



