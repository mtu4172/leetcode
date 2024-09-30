# Link : https://leetcode.com/problems/trapping-rain-water/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = height[0]
        right = height[-1]
        left_max = [0] * len(height)
        right_max = [0] * len(height)

        water = 0

        for i in range(1, len(height)):
            left_max[i] = left
            left = max(left, height[i])
        for i in reversed(range(len(height)-1)):
            right_max[i] = right
            right = max(right, height[i])
        for i, e in enumerate(height):
            temp = min(left_max[i], right_max[i]) - e
            if temp > 0:
                water += temp
        return water

        