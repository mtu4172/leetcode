// Link : https://leetcode.com/problems/ransom-note/

#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char iter : magazine) {
            count[iter - 97]++;
        }
        for (char iter : ransomNote) {
            count[iter - 97]--;
            if (count[iter - 97] < 0)
                return false;
        }
        return true;
    }
};