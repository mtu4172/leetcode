// Link : https://leetcode.com/problems/smallest-range-i/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int iter : nums) {
            mini = min(iter, mini);
            maxi = max(iter, maxi);
        }
        if (maxi - k - mini - k <= 0)
            return 0;
        return abs((maxi - k) - (mini + k));
    }
};