# Link : https://leetcode.com/problems/removing-stars-from-a-string/

class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        stk = []
        for i in s:
            if i == '*':
                stk.pop()
            else:
                stk.append(i)
        return ''.join(stk)
