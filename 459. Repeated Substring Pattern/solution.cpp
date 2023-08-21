// Link : https://leetcode.com/problems/repeated-substring-pattern/

#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.size()/2+1; i++) {
            if (s.size() % i != 0)
                continue;
            int divs = s.size() / i;
            string substr = s.substr(0, i);
            string temp = "";
            for (; divs > 0; divs--) {
                temp += substr;
            }
            if (s == temp)
                return true;
        }
        return false;
    }
};