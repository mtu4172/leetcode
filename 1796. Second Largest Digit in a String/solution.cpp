// Link : https://leetcode.com/problems/second-largest-digit-in-a-string/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int secondHighest(string s) {
        vector<int> arr(10, 0);
        for (char c : s) {
            int v = int(c) - 48;
            if (v >= 0 && v <= 9)
                arr[v]++;
        }
        stack<int> stk;
        for (int i = 0; i < 10; i++) {
            if (arr[i] > 0)
                stk.push(i);
        }
        if (stk.size() < 2)
            return -1;
        stk.pop();
        return stk.top();
    }
};