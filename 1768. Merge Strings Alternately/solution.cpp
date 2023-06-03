// Link : https://leetcode.com/problems/merge-strings-alternately/

#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int len = max(word1.size(), word2.size());
        for (int i = 0; i < len; i++) {
            if (i < word1.size())
                res += word1[i];
            if (i < word2.size())
                res += word2[i];
        }
        return res;
    }
};