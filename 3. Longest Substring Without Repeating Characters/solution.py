# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        letters = {}
        l = 0
        r = 0
        letters[s[0]] = 1
        while r < len(s)-1:
            r += 1
            if s[r] not in letters:
                letters[s[r]] = 1
            else:
                letters[s[r]] += 1
            for i in letters:
                if letters[i] > 1:
                    letters[s[l]] -= 1
                    l += 1
                    break
        return r - l + 1