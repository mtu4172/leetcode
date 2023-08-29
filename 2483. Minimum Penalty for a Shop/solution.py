# Link : https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        penalty = 0
        minP = 2100000000
        minInd = -1
        for c in customers:
            if c == 'Y':
                penalty += 1
        minP = penalty
        for i in range(0, len(customers)):
            if customers[i] == 'Y':
                penalty -= 1
            elif customers[i] == 'N':
                penalty += 1
            if penalty < minP:
                minP = penalty
                minInd = i
        return minInd + 1