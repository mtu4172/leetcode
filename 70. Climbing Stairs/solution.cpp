// Link : https://leetcode.com/problems/climbing-stairs/

#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        vector<int> stairs = {1, 2};
        for (int i = 2; i < n; i++) {
            stairs.push_back(stairs[i-1] + stairs[i-2]);
        }
        return stairs.back();
    }
};