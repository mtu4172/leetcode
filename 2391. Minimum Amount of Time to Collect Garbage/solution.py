# Link : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        M = 0
        P = 0
        G = 0
        count = 0
        total = 0
        for i, e in enumerate(garbage):
            count += len(e)
            if 'M' in e:
                M = i
            if 'P' in e:
                P = i
            if 'G' in e:
                G = i
        total += count
        for i, e in enumerate(travel):
            if i < M:
                count += e
            if i < P:
                count += e
            if i < G:
                count += e
        return count