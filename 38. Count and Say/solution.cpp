// Link : https://leetcode.com/problems/count-and-say/

#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string say = countAndSay(n-1);
        string str = "";
        char val = say[0];
        int run = 0;
        for (char iter : say) {
            if (iter != val) {
                str += to_string(run) + val;
                run = 1;
                val = iter;
            } else {
                run++;
            }
        }
        str += to_string(run) + val;
        return str;
    }
};