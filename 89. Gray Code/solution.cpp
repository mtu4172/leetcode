// Link: https://leetcode.com/problems/gray-code/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> dp;
        int max = pow(2, n);
        dp.push_back(0);
        for (int i = 1; i < max; i++) {
            dp.push_back(i ^ i >> 1);
        }
        return dp;
    }
};