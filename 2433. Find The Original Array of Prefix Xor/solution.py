# Link : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution(object):
    def findArray(self, pref):
        arr = [pref[0]]
        for i in range(1, len(pref)):
            arr.append(pref[i] ^ pref[i-1])
        return arr