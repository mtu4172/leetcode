class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        inds = {}
        for i, n in enumerate(nums):
            if n in inds:
                return [inds[n], i]
            inds[target-n] = i
        return []