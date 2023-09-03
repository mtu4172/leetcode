# Link : https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = []
        arr.append(1)
        arr.append(2)
        arr.append(5)
        if n < 4:
            return arr[n-1]
        for i in range(3, n):
            arr.append(2*arr[i-1] + arr[i-3])
            arr[i] %= 1000000007
        return arr[n-1]
        