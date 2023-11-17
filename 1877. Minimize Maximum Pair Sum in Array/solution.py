# Link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        maxi = 0
        for i in range(len(nums) / 2):
            pairsum = nums[i] + nums[len(nums)-1-i]
            if pairsum > maxi:
                maxi = pairsum
        return maxi
